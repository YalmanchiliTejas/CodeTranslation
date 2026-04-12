#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool t_h;
long long int year,var,tesuryo;
double riritu,hukuiri;

long long int T(long long int shikin){
  int rishi=0;
  for(int i=0;i<year;i++){
    rishi+=riritu*shikin;
    shikin-=tesuryo;
  }
  return rishi+shikin;
}

long long int H(long long int shikin){
  //cout<<"H"<<endl;
  for(int i=0;i<year;i++){
    shikin=shikin*riritu+shikin-tesuryo;
    //cout<<"shikin "<<shikin<<endl;
  }
  //cout<<"end"<<endl;
  return shikin;
}

int main(){
  int n;
  long long int shikin;
  vector<long long int> ans;
  cin>>n;
  for(int i=0;i<n;i++){
    //cout<<"i is "<<i<<endl;
    ans.clear();
    cin>>shikin>>year>>var;
    for(int j=0;j<var;j++){
      //cout<<"j is "<<j<<endl;
      cin>>t_h>>riritu>>tesuryo;
      //cout<<t_h<<endl;
      if(t_h==1)
	ans.push_back(H(shikin));
      else
	ans.push_back(T(shikin));
      //cout<<"LKJL"<<endl;
    }
    sort(ans.begin(),ans.end());
    //cout<<"sort"<<endl;
    cout<<ans.back()<<endl;
  }
  return 0;
}