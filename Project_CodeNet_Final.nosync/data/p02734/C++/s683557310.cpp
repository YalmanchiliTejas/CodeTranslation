#include<bits/stdc++.h>
using lint=long long;
template <class T>
T inverse(T a, T m) {
    T u=0,v=1;
    while(a!=0){
        T t=m/a;
        m-=t*a;std::swap(a,m);
        u-=t*v;std::swap(u,v);
    }
    assert(m==1);
    return u;
}
template <class T>
class modular {
    public:
        int value;
        constexpr modular() = default;
        constexpr modular(const modular&) = default;
        constexpr modular(modular&&) = default;
        modular& operator=(const modular&) = default;
        modular& operator=(modular&&) = default;
        template <class U>modular (const U& x) {value = normalize(x);}

        template <class U>
            static int normalize(const U& x) {
                int v=static_cast<int>(-mod()<=x&&x<mod()?x:x%mod());
                if(v<0)v+=mod();
                return v;
            }

        template <class U> explicit operator U()const{return static_cast<U>(value);}
        constexpr static auto mod(){return T::value;}

        auto&operator+=(const modular&other) {if((value+=other.value)>=mod())value-=mod();return *this;}
        auto&operator-=(const modular& other){if ((value-=other.value)<0)value+=mod();return *this;}
        template <class U>auto& operator+=(const U& other){return*this+=modular(other);}
        template <class U>auto& operator-=(const U& other){return*this-=modular(other);}
        auto operator-()const{return modular(-value);}
        auto&operator++(){return*this+=1;}
        auto&operator--(){return*this-=1;}
        auto operator++(int){modular result(*this);operator++();return result;}
        auto operator--(int){modular result(*this);operator--();return result;}

        template <class U = T>
            auto&operator*=(const modular&rhs){value=normalize(static_cast<std::int64_t>(value)*static_cast<std::int64_t>(rhs.value));return *this;}
        auto&operator/=(const modular&rhs){return*this*=modular(inverse(rhs.value, mod()));}
};
template<class T>struct is_modular:std::false_type{};
template<class T>struct is_modular <modular<T>>:std::true_type{};
template<class T>constexpr bool is_modular_v=is_modular<T>::value;
template<class t> bool operator==(const modular<t>& lhs, const modular<t>& rhs){return lhs()==rhs();}
template<class T,class U>bool operator==(const modular<T>& lhs, U rhs){return lhs==modular<T>(rhs);}
template<class T,class U>bool operator==(U lhs, const modular<T>& rhs){return modular<T>(lhs)==rhs;}
template<class T> bool operator!=(const modular<T>& lhs, const modular<T>& rhs){return !(lhs == rhs);}
template<class T,class U> bool operator!=(const modular<T>& lhs, U rhs){return !(lhs==rhs);}
template<class T,class U> bool operator!=(U lhs, const modular<T>& rhs){return !(lhs==rhs);}
template<class T> modular<T> operator+(const modular<T>& lhs, const modular<T>& rhs){return modular<T>(lhs)+=rhs;}
template<class T,class U> modular<T> operator+(const modular<T>& lhs, U rhs){return modular<T>(lhs)+=rhs;}
template<class T,class U> modular<T> operator+(U lhs, const modular<T>& rhs){return modular<T>(lhs)+=rhs;}
template<class T> modular<T> operator-(const modular<T>& lhs, const modular<T>& rhs){return modular<T>(lhs)-=rhs;}
template<class T,class U> modular<T> operator-(const modular<T>& lhs, U rhs){return modular<T>(lhs)-=rhs;}
template<class T,class U> modular<T> operator-(U lhs, const modular<T>& rhs){return modular<T>(lhs)-=rhs;}
template<class T> modular<T> operator*(const modular<T>& lhs, const modular<T>& rhs){return modular<T>(lhs)*=rhs;}
template<class T,class U> modular<T> operator*(const modular<T>& lhs, U rhs){return modular<T>(lhs)*=rhs;}
template<class T,class U> modular<T> operator*(U lhs, const modular<T>& rhs){return modular<T>(lhs)*=rhs;}
template<class T> modular<T> operator/(const modular<T>& lhs, const modular<T>& rhs){return modular<T>(lhs)/=rhs;}
template<class T, class U> modular<T> operator/(const modular<T>& lhs, U rhs){return modular<T>(lhs)/=rhs;}
template<class T, class U> modular<T> operator/(U lhs, const modular<T>& rhs){return modular<T>(lhs)/=rhs;}
template<class T, class U>
modular<T> power (const modular<T>& a, U b) {
    assert(b>=0);
    modular<T>x=a,ret=1;
    for (;b>0;b/=2){
        if(b%2==1)ret*=x;
        x*=x;
    }
    return ret;
}
template <class t>std::string to_string(const modular<t>& a) {
    return std::to_string(a.value);
}
template <class t>auto operator<<
(std::ostream& os, const t& a)->std::enable_if_t<is_modular_v<t>, std::ostream&>{
    return os << a.value;
}

constexpr int mod = 998'244'353;
using mint = modular<std::integral_constant<std::decay_t<decltype(mod)>, mod>>;

int main(){
    std::cin.tie(nullptr);std::ios_base::sync_with_stdio(false);
    std::cout.setf(std::ios_base::fixed);std::cout.precision(15);
    lint n,S;std::cin>>n>>S;
    std::vector<mint>dp(S+1);
    mint ans=0;
    for(lint i=0;i<n;i++){
        lint x;std::cin>>x;
        if(x<S)ans+=dp.at(S-x)*(n-i);
        if(x==S)ans+=(i+1)*(n-i);
        for(lint j=S;j-x>=0;j--){
            dp.at(j)+=dp.at(j-x);
        }
        if(x<=S)dp.at(x)+=i+1;
    }
    std::cout<<ans<<'\n';
}
