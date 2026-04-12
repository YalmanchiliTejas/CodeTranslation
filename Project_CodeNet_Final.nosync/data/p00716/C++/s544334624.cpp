#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int solve(int money,int year,int type,double per,int mine){
	if(type==1){
		rep(i,year){
			money=money+(int)( money * per);
			money-=mine;
		}
		return money;
	}
	else{
		int tmp=0;
		rep(i,year){
			tmp+=(int)( money * per);
			money-=mine;
		}
		return money+tmp;
	}

}



int main(){
	int m;

	cin>>m;

	rep(loop,m){
		int money,year,n;
		cin>>money>>year>>n;
		int type,mine;
		double per;
		int maxi=-1;
		rep(i,n){
			cin>>type>>per>>mine;
			maxi=max(solve(money,year,type,per,mine),maxi);
		}
		cout<<maxi<<endl;
	}
}

//テ・ツ債佚・ツ按ゥテ」ツδサティツ、ツ?・ツ按ゥテ」ツ?ョテ・ツ按・ テ・ツケツエテ・ツ按ゥテァツ篠?テヲツッツ偲・ツケツエテ」ツ?ョテヲツ可凝ヲツ閉ーテヲツ鳴? 