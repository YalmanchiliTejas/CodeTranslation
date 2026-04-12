#include<map>
#include<set>
#include<cmath>
#include<climits>
#include<vector>
#include<queue>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#define mod 1000000007
#define mo 998244353
using namespace std;
#define LL long long int
int main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N , x , M;
    cin >> N >> x >> M;
    vector<LL> arr;
    set<LL> hash;
    LL repeating=-1;
    while(hash.find(x)==hash.end())
    {
        arr.push_back(x) ;
        hash.insert(x);
        x=(x*x)%M;
    }
    repeating=x;
    if(arr.size() >=N )
    {
        LL sum=0;
        for(LL i=0;i<N;i++)
        {
            sum = (sum + arr[i]); 
        }
        cout<<sum<<endl;
    }
    else
    {
        LL s=0;
        for(auto it:arr)
            s+=it;
        LL sum = 0;
        bool ok = true;
        LL index= -1;
        for(LL i=0;i<arr.size();i++)
        {
            if(arr[i] == repeating)
            {
                ok=false;
                index=i;
                sum=arr[i];
            }
            else if(!ok)
            {
                sum+=arr[i];
            }
        }
        LL M=arr.size()-index;
        N=N-arr.size();
        s= s + sum*(N/M);
        for(LL i=index ;i<index+(N%M);i++)
        {
            s=  s+ arr[i];
        } 
        cout<<s<<endl;
    }
}
