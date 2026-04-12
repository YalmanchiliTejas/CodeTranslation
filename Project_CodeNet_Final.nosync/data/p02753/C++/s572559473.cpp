#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vii;
typedef vector<pair<int,int>> vip;

#define pb push_back
#define ZOOM ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define LOOP_IT(s) for(auto it=(s).begin();it!=(s).end();++it)
#define loop for(int i=0;i<n;++i)


int main(int argc,char* argv[])
{
    ZOOM

    string s;
    cin>>s;bool f=0,f2=0;
    int n=s.size();
    loop
    {
        if(s[i]=='A')
            f=1;
        else
            f2=1;
    }
    if(f&f2)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}

