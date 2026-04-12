#include<bits/stdc++.h>
using lint=long long;
void debug_impl(){std::cerr<<'\n';}
template<class Head,class...Tail>void debug_impl(Head head, Tail... tail){std::cerr << " " << head;debug_impl(tail...);}
    template<class Container,class Value=typename Container::value_type,std::enable_if_t<!std::is_same<Container,std::string>::value,std::nullptr_t> = nullptr>
std::ostream&operator<<(std::ostream&os,Container const&v)
{os<<"{";for(auto it=v.begin();it!=v.end();it++){os<<(it!=v.begin()?",":"")<<*it;}return os<<"}";}
    template<template<class...>class Tuple,class...Args,std::size_t...Inds,std::size_t=std::tuple_size<Tuple<Args...>>::value>
std::ostream&tuple_output_impl(std::ostream&os,const Tuple<Args...>&tuple,std::integer_sequence<std::size_t,Inds...>)
{os<<"(";(void)std::initializer_list<int>{((void)(os<<(Inds>0?",":"")<<std::get<Inds>(tuple)),0)...};return os<<")";}
    template<template<class...>class Tuple,class...Args,std::size_t=std::tuple_size<Tuple<Args...>>::value>
std::ostream&operator<<(std::ostream&os,const Tuple<Args...>&tuple)
{return tuple_output_impl(os,tuple,std::index_sequence_for<Args...>());}
#define DEBUG 1
#if DEBUG
#define debug(...)do{std::cerr<<std::boolalpha<<"["<<#__VA_ARGS__<<"]:";debug_impl(__VA_ARGS__);std::cerr<<std::noboolalpha;}while(false)
#else
#define debug(...) {}
#endif
int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint n,k;std::cin>>n>>k;
    lint ans=0;
    for(lint b=k+1;b<=n;b++){
        ans+=n/b*(b-k)+std::max(0ll,n%b-k+1);
        ans-=(k==0);
    }
    std::cout<<ans<<'\n';
}
/*
 * b (>k) を決め打ちです。
 * a=qb+r の q で、余りがなんでもよいものは、
 * qb+b-1<=n ですから、q<=(n-b+1)/b となり、(n-b+1)/b+1 = (n+1)/b 個です。
 * とくに、0..n/b-1 の n/b 個は大丈夫です。
 * n/b は途中までで、n/b+1 は既に超えていますから、見る必要がありません。　
 * q=n/b とすると、r<=n-qb=n-n/b*b=n%b となり、max(0,n%b-k+1) です。
 * k=0 のとき、(b,0) が毎回入りますから、引きましょう。
 */
