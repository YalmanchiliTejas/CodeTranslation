#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
#include"iomanip"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    list<int>r;
    int n;cin>>n;
    bool a=true;
    for(int i=0;i<n;++i)
    {
       int x;cin>>x;
       if(a)
           r.push_back(x);
       else r.push_front(x);
       a=!a;
    }
    vector<int> rec(r.begin(),r.end());
    int s=rec.size();
    for(int i=0;i<s;++i)
    {
        if(a)
        {
            cout<<rec[i]<<' ';
        }
        else cout<<rec[n-1-i]<<' ';
    }
    cout<<'\n';


}


