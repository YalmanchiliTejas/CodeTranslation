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
    lint n;std::cin>>n;
    std::vector<lint>a(26,1'000'000'000);
    while(n--){
        std::string s;std::cin>>s;
        std::vector<lint>b(26);
        for(char c:s)b.at(c-'a')++;
        for(lint i=0;i<26;i++){
            if(a.at(i)>b.at(i))a.at(i)=b.at(i);
        }
    }
    for(lint i=0;i<26;i++){
        for(lint j=0;j<a.at(i);j++){
            std::cout<<char('a'+i);
        }
    }
    std::cout<<'\n';
}
