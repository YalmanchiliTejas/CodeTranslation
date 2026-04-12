#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define pb push_back
ll mod = 1000000007;
signed main(){

    int h,w,x,y;
    cin >> h >> w;
    vector<vector<char>> v(h,vector<char> (w));

    for(int i=0;i < h;i++)
    {
        for(int j=0;j < w;j++)
        {
            cin >> v.at(i).at(j);
        }
    }

    queue<int> q;
    q.push(0);q.push(0);

    while(q.size()>0){
        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        v.at(x).at(y)='.';
        bool f=false;

        if(x<h-1 && v.at(x+1).at(y)=='#'){
            q.push(x+1);
            q.push(y);
            f=true;
        }
        if(y<w-1 && v.at(x).at(y+1)=='#'&& f==false){
            q.push(x);
            q.push(y+1);
        }
    }
    bool flag=false;
    for(int i=0;i < h;i++)
    {
        for(int j=0;j < w;j++)
        {
            if(v.at(i).at(j)=='#'){
                flag=true;
            }
        }
    }


    if(x==h-1 && y==w-1 && flag==false){
            cout << "Possible" << endl;
        }else{
            cout << "Impossible" << endl;
        }

}


