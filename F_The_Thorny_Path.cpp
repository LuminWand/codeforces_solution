/*
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef CHAPPY_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
*/

#include <bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
int T,n,m,p[1000010],ans,cnt;
bool v[1000010];
void sol(){
    cin>>n,fill(v,v+n+1,0),ans=1,cnt=0;
    int c[3]={};
    bool fl=0;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) if(!v[i]){
        int l=0;
        for(int j=i;!v[j];j=p[j]) v[j]=1,l++;
        cnt+=(l-1)/3;
        if(l%3==1&&l>3) fl=1;
        if(l%3) c[l%3]++;
    }
    while(n>4) ans=3ll*ans%mod,n-=3;
    ans=1ll*ans*n%mod;
    if(n%3==1){
        if(fl&&(c[1]>=c[2]||c[2]<2)){
            c[1]--,cnt--;
        }
        else if(c[2]>=2){
            c[2]-=2;
        }
        else if(c[2]==1){
            c[1]-=2,cnt++,c[2]=0;
        }
        else{
            if(c[1]>=4) c[1]-=4,cnt+=2;
            else c[1]--,cnt++;
        }
    }
    if(n%3==2){
        if(!c[2]) c[1]-=2,cnt++;
        else c[2]--;
    }
    if(c[1]>=c[2]) cnt+=c[2]+(c[1]-c[2])/3*2;
    else cnt+=c[2];
    cout<<ans<<" "<<cnt<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--) sol();
}

/*
int main() {
    ios::sync_with_stdio(false);
#ifndef CHAPPY_DEBUG
    cin.tie(nullptr);
#endif
}
*/
