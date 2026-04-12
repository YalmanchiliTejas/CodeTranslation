#include <bits/stdc++.h>
using namespace std;

int main() {
int h,w;
cin >> h >>  w;
vector<vector<char>> vec(h,vector<char>(w));
vector<int> a(h,0);
vector<int> b(w,0);

for(int i=0;i<h;i++)
{
    for(int j=0;j<w;j++)
    {
        cin >> vec.at(i).at(j);
    }
}
for(int i=0;i<h;i++)
{
    bool x=true;
    for(int j=0;j<w;j++)
    {
        if(vec.at(i).at(j)=='#')
        {
            x=false;
            break;
        }
    }
    if(x) a.at(i)=1;
}
for(int j=0;j<w;j++)
{
    bool y=true;
    for(int i=0;i<h;i++)
    {
        if(vec.at(i).at(j)=='#')
        {
            y=false;
            break;
        }
    }
    if(y) b.at(j)=1;
}
for(int i=0;i<h;i++)
{
    bool z = false;
    for(int j=0;j<w;j++)
    {
        if(a.at(i)==0 && b.at(j)==0)
        {
            cout << vec.at(i).at(j);
            z = true;
        }
    }
    if(z) cout << endl;
}
}