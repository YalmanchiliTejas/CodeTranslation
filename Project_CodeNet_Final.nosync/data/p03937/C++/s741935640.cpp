# include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  char a[n][m];
  int minpos_crr=100;
  int minpos_prev=-1;
  int maxpos_crr=-1;
  int cnt=0;
  bool found =false;
 int v=0;
  for(int i=0;i<n;i++)
   {
     cnt=0;
     //cout <<1<<" "<<(++v)<<"\n";
     for(int j=0;j<m;j++)
      {
        //cout <<2<<" "<<(++v)<<"\n";
        cin >> a[i][j];
        if(a[i][j]=='#')
         {
           cnt++;
           maxpos_crr=max(maxpos_crr,j);
           minpos_crr=min(minpos_crr,j);
         }

      }
      if(minpos_crr!=minpos_prev && i>0)
       found=true;
       minpos_prev=maxpos_crr;
       minpos_crr=100;
      if(!cnt)
       found=true;
   }

   if(found)
    cout << "Impossible"<<"\n";
  else
   cout << "Possible"<<"\n";
   return 0;
}
