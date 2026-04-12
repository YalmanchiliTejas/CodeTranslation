#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  string s;
  int a,b,c,d;
  while(cin>>s){
    if(s=="#")break;
    cin>>a>>b>>c>>d;
    char ma[11][11];
    int h=0,w=0;
    for(int i=0;i<s.size();i++){
	 if(s[i]=='/'){
	   h++;
	   w=0;
	 }else if(s[i]=='b'){
	   ma[h][w++]='b';
	 }else{
	   int k=s[i]-'0';
	   for(int j=0;j<k;j++){
		ma[h][w++]='.';
	   }
	 }
    }
  
    swap(ma[a-1][b-1],ma[c-1][d-1]);
    string tmp="";
    for(int i=0;i<=h;i++){
	 if(i)tmp+='/';
	 for(int j=0;j<w;j++){
	   tmp+=ma[i][j];
	 }
    }
    
    //cout<<tmp<<endl;//<<" "<<h<<" "<<w<<endl;
    /*
	 for(int i=0;i<=h;i++){
	 for(int j=0;j<w;j++){
	 cout<<ma[i][j];
	 }
	 cout<<endl;
	 }*/
    for(int i=0;i<tmp.size();i++){
	 if(tmp[i]=='.'){
	   int cnt=0;
	   while(i<tmp.size()&&tmp[i]=='.'){
		i++;
		cnt++;
	   }
	   cout<<cnt;
	   i--;
	   continue;
	 }
	 cout<<tmp[i];
    }
    cout<<endl;
  }
  return 0;
}

