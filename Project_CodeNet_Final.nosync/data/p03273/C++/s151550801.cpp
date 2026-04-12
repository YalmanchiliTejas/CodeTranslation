#include <bits/stdc++.h>

#include <cstdlib>  // abs() for integer 絶対値求めやつ

#include <cmath>    // abs() for float, and fabs()

#include <algorithm>
#include <vector>
#define rep(i,n) for(int i = 0; i< (n);i++)

#define SORT(a) sort((a).begin(),(a).end());

#define che(a,string) cout<<string<<":"<<(a)<<endl;

#define ch(a,string) cout<<string<<":"<<(a)<<" ";

using namespace std;

typedef pair<int,int> P;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> A(h);//h行分の.#の入る箱を用意しておく。
  rep(i,h){
	  cin>>A[i];
	}
	//#のある行をとりあえずマークする
	vector<bool> B(h,false);
	vector<bool> C(w,false);
  rep(i,h){
	  string a=A[i];
	  rep(j,w){
	  if(a.at(j)=='#'){
		B[i]=true;
		C[j]=true;
		}
		}
	}
	
	//これでとりあえずマーキングはできた。
	rep(i,h){
		string b =A[i];
		bool k = false;
		rep(j,w){
		  char c =b.at(j);
		  if(B[i]&&C[j]){
			  cout << c ;
			  k =true;
			}
		  }
		  if(k){
		  cout<<endl;}
	  }

}

