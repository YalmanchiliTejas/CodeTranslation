#define ANSWER
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>


template <typename T> 
class mylist {
    private:
        std::vector<char> alphabets = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 
    public:
        mylist(long long i)
        {
            list.resize(i);
        }
        mylist()
        {}
        void input();

        std::vector<T> list;
        void sort();
        std::vector<T> sorted();
        std::vector<size_t> argsort();
        int find(T key);

        T pop(size_t i);
        void push(T value);
        void push(mylist<T> list_);

        mylist<T> iloc(mylist<T> list_);
        
        std::string toString();
        void fromString(std::string string);
        void fromAlphabets(std::string string);
        std::string toAlphabets(bool upper);
        template <typename V>
        void add(V value);

        void range();
        void range(long long length);
        void range(long long start,long long end);

        size_t min_index();
        T min();
        size_t max_index();
        T max();
};
namespace mystd
{
long long MOD = std::pow(10,9)+7;
size_t fac_size = std::pow(10,5);
bool calcurated_fac = false; //n!(mod M)
std::vector<long long> fac; //n!(mod M)
std::vector<long long> ifac; //k!^{M-2} (mod M)
template <typename T>
T factorical(T a);
template <typename T>
T LCM(T a, T b);
template <typename T>
T GCD(T a, T b);
template <typename T>
T LCM(std::vector<T> A);
template <typename T>
T GCD(std::vector<T> A);
template <typename T>
T LCM(mylist<T> A);
template <typename T>
T GCD(mylist<T> A);
long long pow(long long x,long long n);
template <typename T>
T C(T n,T r);
void Calcfac(size_t size);
template <typename T>
T mod(T a,T b);
} // namespace mystd

#include <iostream>
#include <vector>
#include <cstdarg>
#include <cmath>
#include <string>

namespace mystd
{
    template<typename T>
    static bool Input(int number,...);
    template<typename T>
    static bool InputArray(std::vector<T> &array);
    static bool InputArrays(long long number,...);
    static bool InputMatrix(std::vector<std::vector<long long>> array);
    static long long min(std::vector<long long> array);
    static long long max(std::vector<long long> array);
    template<typename T>
    static void Print(int number,...);
    template<typename T>
    static void PrintArray(std::vector<T> array,const std::string sep);
};
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <numeric>
// #include <string>
 
// class mystring {
//     public:
//         std::string str;
//         void sort(); 
//         std::string sorted();
//         std::string argsort();
//         int find(std::string key){
//             typename std::string::iterator iter = std::find(string.begin(), string.end(), key);
//             return std::distance(string.begin(), iter);
//         };
// };

#ifndef ANSWER
#include "mylist.hpp"
#endif

template <typename T> 
void mylist<T>::input(){
    mystd::InputArray<T>(list);
}

template <typename T> 
void mylist<T>::sort(){
    std::sort(list.begin(), list.end());
};

template <typename T> 
std::vector<size_t> mylist<T>::argsort(){
    std::vector<size_t> index(list.size());
    std::iota(index.begin(), index.end(), 0);

    std::sort(index.begin(), index.end(), [this](size_t i1, size_t i2) {
        return this->list[i1] < this->list[i2];
    });

    return index;
};

template <typename T> 
int mylist<T>::find(T key){
    typename std::vector<T>::iterator iter = std::find(list.begin(), list.end(), key);
    if (iter == list.end())
    {
        return -1;
    }
    else
    {
        return std::distance(list.begin(), iter);
    }
}

template <typename T> 
T mylist<T>::pop(size_t i){
    T ans = list[i];
    list.erase(list.begin()+i);
    return ans;
}

template <typename T> 
void mylist<T>::push(T value){
    list.push_back(value);
}

template <typename T> 
void mylist<T>::push(mylist<T> list_){
    std::copy(list_.list.begin(),list_.list.end(),std::back_inserter(list_.list));
}

template <typename T> 
mylist<T> mylist<T>::iloc(mylist<T> list_){
    mylist<T> ans;
    for (auto &&i : list_.list)
    {
        ans.list.push_back(list[i]);
    }
    return ans;
}


template <typename T> 
std::string mylist<T>::toString(){
    std::string string(list.begin(), list.end());
    return string;
}

template <typename T> 
void mylist<T>::fromString(std::string string){
    mylist<char> S;
    std::copy(string.begin(), string.end(), std::back_inserter(list));
}

template <typename T> 
void mylist<T>::fromAlphabets(std::string string){
    std::transform(string.begin(), string.end(), string.begin(), ::tolower);
    for (size_t i = 0; i < string.size(); i++)
    {
        typename std::vector<char>::iterator iter = std::find(alphabets.begin(), alphabets.end(), string[i]);
        list.push_back(std::distance(alphabets.begin(), iter));
    }            
}

template <typename T> 
std::string mylist<T>::toAlphabets(bool upper){
    std::string alp;
    for (auto &&i : list)
    {
        alp.push_back(alphabets[i - std::floor(i / alphabets.size()) * alphabets.size()]);
    }
    if (upper)
    {
        std::transform(alp.begin(), alp.end(), alp.begin(), ::toupper);
    }
    
    return alp;     
}

template <typename T> 
template <typename V> 
void mylist<T>::add(V value){
    for (auto &&i : list)
    {
        i+=value;
    }
}

template <typename T> 
void mylist<T>::range(){
    std::iota(list.begin(), list.end(), 0);
}

template <typename T> 
void mylist<T>::range(long long length){
    list.resize(length);
    std::iota(list.begin(), list.end(), 0);
}

template <typename T> 
void mylist<T>::range(long long start,long long end){
    list.resize(end-start);
    std::iota(list.begin(), list.end(), start);
}

template <typename T> 
size_t mylist<T>::min_index(){
    typename std::vector<T>::iterator iter = std::min_element(list.begin(), list.end());
    return std::distance(list.begin(), iter);
}

template <typename T> 
T mylist<T>::min(){
    typename std::vector<T>::iterator iter = std::min_element(list.begin(), list.end());
    return list[std::distance(list.begin(), iter)];
}

template <typename T> 
size_t mylist<T>::max_index(){
    typename std::vector<T>::iterator iter = std::max_element(list.begin(), list.end());
    return std::distance(list.begin(), iter);
}

template <typename T> 
T mylist<T>::max(){
    typename std::vector<T>::iterator iter = std::max_element(list.begin(), list.end());
    return list[std::distance(list.begin(), iter)];
}

#ifndef ANSWER
#include "mymath.hpp"
#endif

template <typename T>
T mystd::factorical(T a)
{
    T ans = 1;
    for (size_t i = 0; i < a; i++)
    {
        ans *= i + 1;
    }
    return ans;
}

template <typename T>
T mystd::LCM(T a, T b)
{
    return a * b / GCD(a, b);
}

template <typename T>
T mystd::GCD(T a, T b)
{
    if (a < b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    T r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

template <typename T>
T mystd::LCM(std::vector<T> a)
{
    if (a.size() < 1)
    {
        return 1;
    }
    else
    {
        T lcm = LCM(a[0], a[1]);
        for (size_t i = 1; i < a.size() - 1; i++)
        {
            T lcm_temp = LCM(lcm, a[i + 1]);
            if (lcm < lcm_temp)
            {
                lcm = lcm_temp;
            }
        }
        return lcm;
    }
}

template <typename T>
T mystd::LCM(mylist<T> a)
{
    if (a.list.size() < 1)
    {
        return 1;
    }
    else
    {
        T lcm = LCM(a.list[0], a.list[1]);
        for (size_t i = 1; i < a.list.size() - 1; i++)
        {
            T lcm_temp = LCM(lcm, a.list[i + 1]);
            if (lcm < lcm_temp)
            {
                lcm = lcm_temp;
            }
        }
        return lcm;
    }
}

template <typename T>
T mystd::GCD(std::vector<T> a)
{
    if (a.list.size() < 1)
    {
        return 1;
    }
    else
    {
        T gcd = GCD(a[0], a[1]);
        for (size_t i = 1; i < a.size() - 1; i++)
        {
            T gcd_temp = GCD(gcd, a[i + 1]);
            if (gcd < gcd_temp)
            {
                gcd = gcd_temp;
            }
        }
        return gcd;
    }
}

template <typename T>
T mystd::GCD(mylist<T> a)
{
    if (a.list.size() < 1)
    {
        return 1;
    }
    else
    {
        T gcd = GCD(a.list[0], a.list[1]);
        for (size_t i = 1; i < a.list.size() - 1; i++)
        {
            T gcd_temp = GCD(gcd, a.list[i + 1]);
            if (gcd < gcd_temp)
            {
                gcd = gcd_temp;
            }
        }
        return gcd;
    }
}

long long mystd::pow(long long x, long long n)
{
    long long ans = 1;
    while (n != 0)
    {
        if (n & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

template <typename T>
T mystd::C(T n, T r)
{
    if (!calcurated_fac) Calcfac(fac_size);
    if (n == 0 && r == 0)
        return 1;
    if (n < r || n < 0)
        return 0;
    T tmp = ifac[n - r] * ifac[r] % MOD;
    return tmp * fac[n] % MOD;
}

void mystd::Calcfac(size_t size)
{
    fac.resize(size + 1);
    ifac.resize(size + 1);
    fac[0] = 1;
    ifac[0] = 1;
    for (long long i = 0; i < size; i++)
    {
        fac[i + 1] = fac[i] * (i + 1) % MOD;               // n!(mod MOD)
        ifac[i + 1] = ifac[i] * pow(i + 1, MOD - 2) % MOD; // k!^{MOD-2} (mod MOD) ←累乗にmpowを採用
    }
    calcurated_fac = true;
}

template <typename T>
T mystd::mod(T a, T b)
{
	return a - std::floor((long double)a / b) * b;
}
#ifndef ANSWER
#include "mystd.hpp"
#endif

template<typename T>
bool mystd::Input(int number,...){
    va_list args;
    va_start(args, number);
    for (long long i = 0; i < number; i++)
    {
        std::cin >> *(va_arg(args, T*));
    }
    return true;
}

template<typename T>
void mystd::Print(int number,...){
    va_list args;
    va_start(args, number);
    for (long long i = 0; i < number; i++)
    {
        if(i!=0){
            std::cout << " ";
        }
        std::cout << *(va_arg(args, T*));
    }
    std::cout << std::endl;;
}

template<typename T>
void mystd::PrintArray(std::vector<T> array,const std::string sep){
    for (long long i = 0; i < array.size(); i++)
    {
        if(i!=0){
            std::cout << sep;
        }
        std::cout << array[i];
    }
    std::cout << std::endl;;
}

template<typename T>
bool mystd::InputArray(std::vector<T> &array){
    for (size_t i = 0; i < array.size(); i++)
    {
        std::cin >> array[i];
    }
    return true;
}

bool mystd::InputArrays(long long number,...){
    va_list args;
    va_start(args, number);
    std::vector<std::vector<long long>*> arrays(number);
    for (auto &i : arrays)
    {
        i = va_arg(args, std::vector<long long>*);
    }
    long long length = arrays[0]->size();

    for (long long j=0;j<length;j++)
    {
        for (auto &&i : arrays)
        {
            std::cin >> (*i)[j];
        }
    }
    return true;
}


long long mystd::min(std::vector<long long> array){
    long long ans = array[0];
    for (long long &i : array)
    {
        if(i < ans){
            ans = i;
        }
    }
    return ans;
}


long long mystd::max(std::vector<long long> array){
    long long ans = array[0];
    for (long long &i : array)
    {
        if(i > ans){
            ans = i;
        }
    }
    return ans;
}

// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <numeric>
// #include <string>
 
// class mystring {
//     public:
//         std::string str;
//         void sort(); 
//         std::string sorted();
//         std::string argsort();
//         int find(std::string key){
//             typename std::string::iterator iter = std::find(string.begin(), string.end(), key);
//             return std::distance(string.begin(), iter);
//         };
// };

#ifndef ANSWER
#include "../../library/mystd.cpp"
#include "../../library/mylist.cpp"
#include "../../library/mymath.cpp"
#endif

typedef long long ll;
typedef std::vector<long long> vll;
typedef long double ld;
typedef std::vector<long double> vld;

using namespace mystd;

void Main(){
    std::string S;
    std::cin >> S;
    if (S == std::string("AAA") || S == std::string("BBB")){
        std::cout << "No" << std::endl;
    }
    else
    {
        std::cout << "Yes" << std::endl;
        /* code */
    }
    
    
}

int main(int argc, char const *argv[])
{
    Main();
    return 0;
}