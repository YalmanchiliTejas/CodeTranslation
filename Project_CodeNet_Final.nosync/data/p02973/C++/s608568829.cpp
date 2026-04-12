#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N_MAX = 100001;
int main()
{
  int n,i,j=0,a,t=-1,res=1;
  vector<int> v;
  decltype(v)::iterator it;
  cin >> n;
  cin >> a;
  v.push_back(a);
  for(i=1;i<n;i++){
    cin >> a;
    it=upper_bound(v.begin(),v.end(),a,greater<int>());
    if(it==v.end()){
      v.push_back(a);
    } else {
      *it=a;
    }
  }
  cout << v.size() << endl;
  return 0;
}
