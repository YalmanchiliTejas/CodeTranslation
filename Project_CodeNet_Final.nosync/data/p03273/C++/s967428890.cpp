#include <bits/stdc++.h>
using namespace std;
vector< vector<char> > a;
int main(void){
    int H,W;
    cin>>H>>W;


    a = vector< vector<char> >(H, vector<char>(W, 0));

    vector<int> hcount(H);
    vector<int> wcount(W);

    for(int i=0;i<H;i++){
      hcount[i] = 0;
    }
    for(int i=0;i<W;i++){
      wcount[i] = 0;
    }

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        cin>>a[i][j];
      }
    }


    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
          if(a[i][j]=='.') hcount[i]++;
      }
    }
    for(int i=0;i<W;i++){
      for(int j=0;j<H;j++){
          if(a[j][i]=='.') wcount[i]++;
      }
    }



    // for(int i=0;i<H;i++){
    //       cout<<hcount[i]<<endl;
    // }
    // for(int i=0;i<W;i++){
    //       cout<<wcount[i]<<endl;
    // }
    //
    //
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(!(hcount[i]==W||wcount[j]==H)){
          cout<<a[i][j];
        }
        }
        if(!(hcount[i]==W)){
        cout<<endl;
      }
    }

    return 0;
}
