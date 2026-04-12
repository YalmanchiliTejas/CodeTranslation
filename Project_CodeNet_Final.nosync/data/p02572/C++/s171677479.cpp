#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<class T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<class T,class Size=typename vector<T>::size_type>inline auto vector_2d(Size h,Size w,T v){return vector<vector<T>>(h,vector<T>(w,v));}
template<class RandomAccessIterator,class Pair=typename iterator_traits<RandomAccessIterator>::value_type>inline void sort_pairs_by_second(RandomAccessIterator first,RandomAccessIterator last){sort(first,last,[](const Pair&p1,const Pair&p2){return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);});}

int main()
{
    constexpr ll mod=1e9+7;
    ll n=in();
    vector<ll>a(n);
    ll sum=0;
    for(ll i=0;i<n;++i){
        a[i]=in();
        sum=(sum+a[i])%mod;
    }
    ll ans=0;
    for(ll i=0;i<n;++i){
        sum=(mod+sum-a[i])%mod;
        ans=(ans+a[i]*sum)%mod;
    }
    cout<<ans<<endl;
}
