#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin>>H>>W;
    char bord[H][W];
    set<int> x;
    set<int> y; 
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cin>>bord[i][j];
            if(bord[i][j] == '#'){
                x.insert(i);
                y.insert(j);
            }
        }
    }
    int a[x.size()];
    int b[y.size()];
    int i = 0;
      for(auto itr = x.begin(); itr != x.end(); ++itr) {
        a[i] = *itr;
        i++;
    }
    i = 0;
    for(auto itr = y.begin(); itr != y.end(); ++itr) {
        b[i] = *itr;
        i++;
    }
   for(int i = 0;i < x.size();i++){
       for(int j = 0;j < y.size();j++){
           cout<<bord[a[i]][b[j]];
       }
       cout<<endl;
   }
}

