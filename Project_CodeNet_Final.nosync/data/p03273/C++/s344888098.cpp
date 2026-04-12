#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

ll h,w;
cin>>h>>w;

vector<string> v(h);

bool arr1[500] = {false};
bool arr2[500] = {false};

for(ll i=0;i<h;i++)
{
    cin>>v[i];
}

for(ll i=0;i<h;i++)
{
    for(ll j=0;j<w;j++)
    {
        if(v[i][j]=='#')
        {
            arr1[i] = true;
            break;
        }
    }
}


for(ll i=0;i<w;i++)
{
    for(ll j=0;j<h;j++)
    {
        if(v[j][i]=='#')
        {
            arr2[i] = true;
            break;
        }
    }
}

vector<string> ans;


for(ll i=0;i<h;i++)
{
    string temp;
    if(!arr1[i])
        continue;
    for(ll j=0;j<w;j++)
    {
        if(!arr2[j])
            continue;
        temp += v[i][j];
    }
    ans.push_back(temp);
}

//cout<<ans[0].size();

for(ll i=0;i<ans.size();i++)
{
    for(ll j=0;j<ans[0].size();j++)
    {
        cout<<ans[i][j];
    }
    cout<<endl;
}

return 0;
}
