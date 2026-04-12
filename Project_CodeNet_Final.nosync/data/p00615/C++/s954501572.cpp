#include <iostream>
using namespace std;

int main(){
  int n,m,tl[10000],tr[10000],ta[20000],tri,tli,tai;
  int t;
  while (1){
    cin >> n >> m;

    if (n==0&&m==0) break;
    tri =0;
    tli=0;
    tai=0;
    for (int i=0;i<n;i++)
      cin >> tl[i];

    for (int i=0;i<m;i++)
      cin >> tr[i];

    while (tai<n+m){
      if (tri>=m){ ta[tai++]=tl[tli++];continue;}
      if (tli>=n){ ta[tai++]=tr[tri++];continue;}

      if (tr[tri]>tl[tli]){
	ta[tai++]=tl[tli++];
      }	else if(tr[tri]<tl[tli]){
        ta[tai++]=tr[tri++];
      }else {
	ta[tai++]=tl[tli++];
        ta[tai++]=tr[tri++];
      }
    }
    //for (int i=0;i<tai;i++)
    //  cout << ta[i]<<" ";
    //cout <<endl;
    t=ta[0];
    for (int i=1;i<tai;i++){
      if (t<ta[i]-ta[i-1]) t=ta[i]-ta[i-1];
    }
    cout << t <<endl;
  }
  return 0;
}