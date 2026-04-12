#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fr first
#define sc second
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> pip; 
const int INF = (1<<25);
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

struct DATA{
  string s;
  int score;
};
int main(){
  int n;
  int cnt=0;
  while(cin>> n,n){
    if(cnt!=0){
      cout<< endl;
    }
    cnt++;
    DATA data[10],temp;
    for(int i=0;i<n;i++){
      int a,b,c;
      cin>> data[i].s>> a>> b>> c;
      data[i].score=a*3+c;
    }

    for(int i=0;i<n;i++){
      for(int j=n-1;j>i;j--){
	if(data[j].score>data[j-1].score){
	  temp=data[j];
	  data[j]=data[j-1];
	  data[j-1]=temp;
	}
      }
    }

    for(int i=0;i<n;i++){
      cout<< data[i].s<< ","<< data[i].score<< endl;
    }
  }
}