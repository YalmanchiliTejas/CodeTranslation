#include<algorithm>
#include<bitset>
#include<iostream>
#include<iomanip>
#include<set>
#include<string>
#include<math.h>
#include<stack>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;

//--------------
///#define DEBUG
//--------------

#ifdef DEBUG
	#define debugprint(x) cout<<x<<" "
	#define debugendl cout<<endl
	#define debug(x) x
#else
	#define debugprint(x)
	#define debugendl
	#define debug(x)
#endif

class zahyo{
	public:
	int x;
	int y;
	zahyo(){
		x=0;
		y=0;
	}
	zahyo(int x_,int y_){
		x=x_;
		y=y_;
	}
	void print(){
		cout<<x<<" "<<y;
	}
	zahyo operator+(zahyo add){
		add.x=this->x+add.x;
		add.y=this->y+add.y;
		return add;
	}
	zahyo operator-(zahyo add){
		add.x=this->x-add.x;
		add.y=this->y-add.y;
		return add;
	}
	zahyo operator*(int t){
		zahyo temp;
		temp.x=this->x*t;
		temp.y=this->y*t;
		return temp;
	}
	zahyo operator%(int t){
		zahyo temp(this->x%t,this->y%t);
		return temp;
	}
	zahyo operator/(int t){
		zahyo temp(this->x/t,this->y/t);
		return temp;
	}
	bool operator==(const zahyo add) const{
		if(add.x==this->x and add.y==this->y){return true;}
		else{return false;}
	}
	bool operator!=(const zahyo add) const{
		if(add.x==this->x or add.y==this->y){return false;}
		else{return true;}
	}
	bool operator<(const zahyo add) const{
		if(this->x<add.x){return true;}
		else if(this->x==add.x and this->y<add.y){return true;}
		else{return false;}
	}
	bool operator>(const zahyo add) const{
		if(this->x>add.x){return true;}
		else if(this->x==add.x and this->y>add.y){return true;}
		else{return false;}
	}
	void input(){
		cin>>x>>y;
	}
};
int mae[200000]={};
int ato[200000]={};
int main(){
	int n;
	long long int mod=1000000007LL;
	cin>>n;
	long long int ans=0;
	long long int allsum=0;
	for(int i=0;i<n;i++){
		long long int t;
		cin>>t;
		ans=(ans-t*t)%mod;
		while(ans<0){ans+=mod;}
		allsum=(allsum+t)%mod;
	}
	int nijyo=(allsum*allsum)%mod;
	nijyo=(nijyo+ans)%mod;
	if(nijyo%2==0){cout<<nijyo/2<<endl;}
	else{cout<<(nijyo+mod)/2<<endl;}

	return 0;
}
