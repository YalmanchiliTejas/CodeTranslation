#include<iostream>
#include <vector>
using namespace std;
int N_MAX = 100;
int main()
{
  int h,w;
  cin >> h >> w;
  string s[N_MAX];
  bool isb[N_MAX];
  string b="#";
  for(int i=0;i<h;){
    cin >> s[i];
    if(s[i].find(b)==string::npos)
      h--;
    else
      i++;
  }
  fill(isb,isb+w,0);
  for(int j=0;j<w;j++)
    for(int i=0;i<h;i++)
      if(b.compare(s[i].substr(j,1))==0){
        isb[j]=1;
        break;
      }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      if(isb[j])
        cout << s[i].substr(j,1);
    cout << endl;
  }
  return 0;
}