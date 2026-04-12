#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    auto a = vector<vector<int>>(h,vector<int>(w,0));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {   
            char c;
            cin >> c;
            if(c =='.') a[i][j] = 1;            
        }   
    }
    
    auto row = vector<int>(h,0);
    auto col = vector<int>(w,0);
    for (int i = 0; i < h; i++)
    {
        row[i] =   accumulate(a[i].begin(),a[i].end(),1,[](int sum,int num){
            return sum*num;
        });
    }

    for (int j = 0; j < w; j++)
    {
        int ans = 1;
        for (int i = 0; i < h; i++)
        {
            ans *=a[i][j];
        }
        col[j]=ans;
    }

    for (int i = 0; i < h; i++)
    {
        if(row[i]==1) continue;
        for (int j = 0; j < w; j++)
        {
            if(col[j]==1) continue;
            cout << (a[i][j]==1 ? '.':'#');
        }
        cout << endl;
        /* code */
    }
    

}