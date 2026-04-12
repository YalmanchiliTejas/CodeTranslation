#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>

#define int long long
#define double long double
#define incin(n) int (n); cin >> (n)
#define uniq(v) sort((v).begin(),(v).end()); (v).erase(unique((v).begin(),(v).end()),(v).end());
#define steprap(i,n,s) for(int (i)=0;i<(s)*(n);(i)+=(s))
#define rap(i,n) steprap((i),(n),1)

using intV = std::vector<int>;

using namespace std;
namespace math
{
	double PI = 3.14159265359;
	int step(int n);
	int ncr(int n,int r);
	int npr(int n,int r);
	int gcm(int a,int b);
	int lcm(int a,int b);

	int step(int n){
		if(n<=1){
			return 1;
		}else{
			return n * step(n-1);
		}
	}
	int ncr(int n,int r){
		for(int i=1;i<r;i++){
			n *= n-i;
		}
		for(int i=1;i<r;i++){
			r *= r-1;
		}
		return n/r;
	}
	int npr(int n,int r){
		for (int i = 1; i < r; ++i)
		{
			n *= n-1;
		}
		return n;
	}
	int gcm(int a,int b){
		int p=max(a,b);
		int q=min(a,b);
		int r;
		while(true){
			if(p%q==0){
				return q;
			}
			r = p%q;
			p=q;
			q=r;
		}
	}
}

using namespace std;
// using StringMap = std::vector<std::vector<char>> map(h+2,vector<char>(w+2,'#'));
namespace tmp {
    template <typename T> bool inArry(T x,vector<T> v);
    template <typename T> void input(int n,vector<T> &v);

    template <typename T> bool inArry(T x,vector<T> v){
        int l = v.size();
        for(int i=0;i<l;i++){
            if(x==v[i]){
                return true;
            }
        }
        return false;
    }
    
    template <typename T> void input(int n,vector<T> &v){
        for(int i=0;i<n;i++){
            cin >> v.at(i);
        }
    }
}

using namespace std;

signed main (){
	char c;
	cin >> c;
	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
		cout<<"vowel"<<endl;
	}else{
		cout<<"consonant"<<endl;
	}
	return 0;
}
