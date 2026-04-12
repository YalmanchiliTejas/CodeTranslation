#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
 string t,p;
 cin>>t>>p;
 int f=0,s=-1;// second 
 vector<bool> used(26,false);
 vector<int> alpha(26,-1);//最後に使われた位置
 for(ll i=0;i<t.size();i++){
  
  if( s != -1 ){
   if( t[i] == p[s] ) s++;
  }

  if( alpha[ t[i]-'a' ] != -1 ){
   s = max( s , alpha[t[i]-'a' ] );
  }



  if( f<p.size() && t[i] == p[f] ){
   f++;
   alpha[t[i]-'a'] = f;
  }


  if( s == p.size() ){
   cout<<"no"<<endl;
   return 0;
  }

 }

 if( f == p.size() ){
  cout<<"yes"<<endl;
 }else{
  cout<<"no"<<endl;
 }

    return 0;
}

