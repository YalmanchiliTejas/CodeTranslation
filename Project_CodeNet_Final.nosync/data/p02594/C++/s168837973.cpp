#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
//change null_type here for map/set
typedef tree<int,null_type,less<int>,rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;
typedef long long int  ll;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define F first
#define S second

template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    x*=sgn; return ~c;
}
///START HERE
///indexed_set pbd;
//pbd.insert()
//auto x = pbd.find_by_order(2);
//int od=pbd.order_of_key(7)
///rope<int> rp;
//rp.push_back()
//RandomAccess like vector
//mutable_begin, mutable_end()

int main(){
    ///read()+printf
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //fast;
    int x;
    cin>>x;if(x<30){
        cout<<"No";
    }
    else{
    cout<<"Yes";
    }


    return 0;
}
