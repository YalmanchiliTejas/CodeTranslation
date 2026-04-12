#include <bits/stdc++.h>

using namespace std;

int main()
{

  char arr[105][105];

  int flagH[105],flagW[105];
    int h,w;

    cin>>h>>w;

    int i,j;

     for(i=0;i<h;i++){

        for(j=0;j<w;j++){

            cin>>arr[i][j];
        }

     } /// end of scan

    int cnt1 =0 , cnt2 =0;

     for(i=0;i<h;i++){

        for(j=0;j<w;j++){

        if(arr[i][j]=='.')cnt1++;

        }

        if(cnt1 == w){
            flagH[i]=1;
        }
        else{
            flagH[i]=0;
        }
              cnt1 =0;
     }

       




     for(i=0;i<w;i++){

        for(j=0;j<h;j++){

        if(arr[j][i]=='.')cnt2++;

        }

        if(cnt2 == h){
            flagW[i]=1;
        }
        else{
            flagW[i]=0;
        }

            cnt2 =0;
     }

       


     for(i=0;i<h;i++){

        for(j=0;j<w;j++){

          if(flagH[i]==0){

           if(flagW[j]==0){
            printf("%c",arr[i][j]);
          }
          }

        }

        if(flagH[i]==0){
          printf("\n");
        }

     }

    return 0;
}
