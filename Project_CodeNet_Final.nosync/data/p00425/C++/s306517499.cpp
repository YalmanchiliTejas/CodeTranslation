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



int main(){
	int tmpi;
	for(;;){
		int n=input<int>();
		if(n==0)break;
		int U=1,S=2,E=3,ans=1;
		repeat(i,n){
			string tmp=input<string>();
			      if(tmp=="North"){
				tmpi=U;
				U=S;
				S=7-tmpi;
			}else if(tmp=="East"){
				tmpi=E;
				E=U;
				U=7-tmpi;
			}else if(tmp=="West"){
				tmpi=U;
				U=E;
				E=7-tmpi;
			}else if(tmp=="South"){
				tmpi=S;
				S=U;
				U=7-tmpi;
			}else if(tmp=="Right"){
				tmpi=S;
				S=E;
				E=7-tmpi;
			}else if(tmp=="Left"){
				tmpi=E;
				E=S;
				S=7-tmpi;
			}
			ans += U;
		}
		cout << ans << endl;
	}
	return 0;
}