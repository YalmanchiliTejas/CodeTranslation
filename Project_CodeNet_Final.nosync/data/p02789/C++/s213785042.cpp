#include <bits/stdc++.h>
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long
#define s8 char
#define s16 short
#define s32 int
#define s64 long
#define f32 float
#define f64 double
#define forin(x,y) for(auto& x: y)
#define iter(i,c) for(auto i=0; i<c; ++i)

using namespace std;
template<class T> T max(const vector<T> &x){return *std::max_element(x.begin(), x.end());}
template<class T> T min(const vector<T> &x){return *std::min_element(x.begin(), x.end());}
template<class T> size_t argmax(const vector<T> &x){auto iter = std::max_element(x.begin(), x.end()); return std::distance(x.begin(), iter);}
template<class T> size_t argmin(const vector<T> &x){auto iter = std::min_element(x.begin(), x.end()); return std::distance(x.begin(), iter);}
template<class T> T sum(const vector<T> &x){ return std::accumulate(x.begin(), x.end());}
template <class T> void sort(vector<T> &x){sort(x.begin(), x.end());}
template <class T, class Compare> void sort(vector<T> &x, Compare comp){sort(x.begin(), x.end(),comp);}
template<class T> void len(const vector<T> &x){return x.size();}
template<class T> ostream& operator<<(ostream& os, const vector<T> &x){forin(y,x)os<<y<<" "; return os;}

template<class T, size_t SIZE> T max(const array<T,SIZE> &x){return *std::max_element(x.begin(), x.end());}
template<class T, size_t SIZE> T min(const array<T,SIZE> &x){return *std::min_element(x.begin(), x.end());}
template<class T, size_t SIZE> size_t argmax(const array<T,SIZE> &x){auto iter = std::max_element(x.begin(), x.end()); return std::distance(x.begin(), iter);}
template<class T, size_t SIZE> size_t argmin(const array<T,SIZE> &x){auto iter = std::min_element(x.begin(), x.end()); return std::distance(x.begin(), iter);}
template<class T, size_t SIZE> T sum(const array<T,SIZE> &x){ return std::accumulate(x.begin(), x.end());}
template<class T, size_t SIZE> void sort(array<T,SIZE> &x){sort(x.begin(), x.end());}
template<class T, size_t SIZE, class Compare> void sort(array<T,SIZE> &x, Compare comp){sort(x.begin(), x.end(),comp);}
template<class T, size_t SIZE> ostream& operator<<(ostream& os, const array<T,SIZE> &x){forin(y,x)os<<y<<" "; return os;}

int main(void){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;
    if(N==M)cout<<"Yes";
    else cout<<"No";
}