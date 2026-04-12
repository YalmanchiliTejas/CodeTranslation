#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int h, w;
    cin>>h>>w;
    char sq[h][w];
    bool is_wr[h];
    bool is_wc[w];
    for(int i=0; i<h; i++)
    {
        is_wr[i]=true;
        for(int j=0; j<w; j++)
        {
            cin>>sq[i][j];
            if(sq[i][j]=='#') is_wr[i] = false;
        }
    }
    for(int j=0; j<w; j++)
    {
        is_wc[j]= true;
        for(int i=0; i<h; i++)
        {
            if(sq[i][j]=='#') is_wc[j] = false;
        }
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(is_wr[i]||is_wc[j]) continue;
            else cout<<sq[i][j];
        }
        if(!is_wr[i]) cout<<endl;
    }
	return 0;
}
