#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
using namespace std;

int main(){
  vector<pair<long long,int> > vepa;
  pair<long long,int> pa;
  long long n,t,d,sta,end,max;
  long long sum;
  cin>>n;
  pa.first=0;
  pa.second=0;
  vepa.push_back(pa);
  t=0;
  sum=0;
  for(int i=0;i<n;i++){
    cin>>d;
    sum+=d;
    t++;
    pa.first=sum;
    pa.second=t;
    vepa.push_back(pa);
  }
  //  for(int i=0;i<vepa.size();i++)cout<<vepa[i].first<<" "<<vepa[i].second<<endl;////
  sort(vepa.begin(),vepa.end());
  // cout<<endl;//////////
  //for(int i=0;i<vepa.size();i++)cout<<vepa[i].first<<" "<<vepa[i].second<<endl;////
  sta=vepa[0].second;
  end=0;
  max=0;
  for(int i=0;i<vepa.size();i++){

    if(vepa[i].first!=vepa[i+1].first){
      if(max<=vepa[i].second-sta){
	max=vepa[i].second-sta;
	//cout<<max<<" "<<i<<"koredesu"<<endl;////////////
      }
      sta=vepa[i+1].second;
    }else if(i==vepa.size()-1){
      if(max<vepa[i].second-sta)max=vepa[i].second-sta;
    }

    //cout<<sta<<"<==="<<endl;/////////
  }
  cout<<max<<endl;
  return 0;
}