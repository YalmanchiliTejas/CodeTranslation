#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++ )
#define repf(i,m,n) for(int (i)=m;(i)<n;(i)++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define vec(name,num) vector<ll> name((num),0);
#define op(i) cout<<(i)<<endl;
#define ip(i) cin>>(i);
#define opN cout<<"No"<<endl;
#define opY cout<<"Yes"<<endl;
#define opP cout<<"Possible"<<endl;
#define opI cout<<"Impossible"<<endl;
#define mat(name,fnum,snum); vector<vector<ll>> name((fnum),vector<ll>((snum),0));
#define debugP int debug_point; cin>>debug_point;
const ll MOD= 1e9 + 7;
template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
ll pown(ll fi,ll se){
  ll ans=1;
  rep(i,se){
    ans*=fi;
  }
  return ans;
}
template <class T>
vector<T> getv(ll n){
	vector<T> Vector_temp;
	rep(i,n){
		T input;
		cin >> input;
		Vector_temp.emplace_back(input);
	}
	return Vector_temp;
}
ll gcd(ll c,ll b){
    while(1){
        if(c%b!=0){
        ll tmp=b;
        b=c%b;
        c=tmp;
        }else{
            return b;
        }
    }
}

/* <3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3*/

ll func(ll now,ll mai,ll uf){
  if(now==0){   return 1;}
  else if(mai==uf){
    //op(1);
    return 1+2*func(now-1,(mai-3)/2,(mai-3)/2);
  }else if(uf>((mai-3)/2+2)){
    //op(2);
    return 1+func(now-1,(mai-3)/2,(mai-3)/2)+func(now-1,((mai-3)/2),uf-(mai-3)/2-2);
  }else if(uf==((mai-3)/2+2)){
    //op(3);
    return 1+func(now-1,(mai-3)/2,(mai-3)/2);
  }else if(uf>1){
    //op(4);
    return func(now-1,(mai-3)/2,uf-1);
  }else {
    //op(5);
    return 0;
  }
}


int main(){
 ll n,x;
 cin>>n>>x;
 ll mai=1;
rep(i,n){
mai*=2;
mai+=3;
}
op(func(n,mai,x));
  return 0;
}