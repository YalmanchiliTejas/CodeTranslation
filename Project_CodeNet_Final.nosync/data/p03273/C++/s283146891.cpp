//g++  5.4.0

#include <iostream>
using namespace std;

int main()
{
    int h, w, id=0;
    cin>>h>>w;
    string g[h +3], wh;
    for(int i=0; i<w; i++) wh += ".";
    for(int i = 0; i < h; i++)
    {
        string a;
        cin>>a; cin.ignore();
        if(a!=wh) g[id++] = a;
    }
    for(int i = 0; i < w; i++)
    {
       int ck = 0;
       for(int j = 0; j<id; j++) if(g[j][i]=='.') ck++;
       if(ck == id) for(int j = 0; j < id; j++) g[j][i] = '*';
    }
    for(int i = 0; i < id; i++)
    {
        for(int j = 0; j < w; j++)
           if(g[i][j]!= '*') cout << g[i][j];
        cout<<endl;
    }
    return 0;
}