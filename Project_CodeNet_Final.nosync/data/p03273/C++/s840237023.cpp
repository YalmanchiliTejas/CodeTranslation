#include <bits/stdc++.h>
using namespace std;
int main(){
 int h,w;
 cin >> h >> w;
 vector<vector<char>> a(h,vector<char>(w));
 for(int i = 0; i < h; i++){
     for(int j = 0; j < w; j++){
         cin >> a[i][j];
     }
 }
vector<int> b(h,100000),c(w,100000);
int k = 0;
for(int i = 0; i < h; i++){
    bool d = true;
    for(int j = 0; j < w; j++){
        if(a[i][j] == '#')
        d = false;
    }
    if(d){
    b[k] = i;
    k++;
    }
}
int l = 0;
for(int i = 0; i < w; i++){
    bool e = true;
    for(int j = 0; j < h; j++){
        if(a[j][i] == '#')
        e = false;
    }
    if(e)
    {
        c[l] = i;
        l++;
    }
}
int s = 0;
for(int i = 0; i < h; i++){
    int cnt = 0;
    int t = 0;
    for(int j = 0; j < w; j++){
       if(i != b[s] && j != c[t])
         cout << a[i][j];
         if(i == b[s]){
         cnt++;
         break;
         }
         if(j == c[t])
         t++;
    }
    if(cnt == 0)
    cout << endl;
    if(cnt > 0)
    s++;
}
}