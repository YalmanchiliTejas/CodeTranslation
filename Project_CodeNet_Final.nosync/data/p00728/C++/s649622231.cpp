#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

// this require C++11
//#include <unordered_set>
//#include <unordered_map>
//#include <random>

using namespace std;

#define all(c) c.begin(),c.end()
#define repeat(i,n) for(int i=0;i<static_cast<int>(n);i++)
#define debug(x) #x << "=" << (x)
#define dump(x) cerr << debug(x) << " (L:" << __LINE__ << ")"<< endl

typedef long long ll;
typedef vector<int> vi;

template<typename T>
ostream& operator<<(ostream& os,vector<T>& vec){
    typename vector<T>::iterator it,endit=vec.end();
    os << "[";
    for(it=vec.begin();it!=endit;it++){
        os << " " << *it << ",";
    }
    os << "]";
    return os;
}

template<typename T>
T input(){
    T t;cin >> t;
    return t;
}

template<typename T>
vector<T> input(const int N){
    vector<T> v(N);
    repeat(i,N) cin >> v[i];
    return v;
}

int solve(int N){
    int av=0,in,mn,mx;
    for(int i=0;i<N;i++){
        cin >> in;
        av+=in;
        if(i==0){
            mn=in;
            mx=in;
        }
        if(mx<in)   mx = in;
        if(mn>in)   mn = in;
    }
    return (av-mx-mn)/(N-2);
}

int main(){
    int N;
    for(;;){
        cin >> N;
        if(N==0)
            break;
        cout << solve(N) << endl;
    }
	return 0;
}