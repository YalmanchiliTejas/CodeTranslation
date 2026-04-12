#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;
using vec = vector<int>;
using lst = list<int>;

bool solve()
{
    int n,l,r;
    cin >> n >> l >> r;

    if(n==0)return 0;

    vec ar(r-l+1);
    lst A;

    for(int i=0;i<n;++i)
    {
        int a;cin >> a;
        A.push_back(a);
    }
    A.push_back(1);

    while(!A.empty())
    {
        for(int i=l;i<=r;++i)
        {
            if(i%A.back()==0)
            {
                ar[i-l] = A.size() % 2;
            }
        }
        A.pop_back();
    }

    int ans = 0;
    for(int i=l;i<=r;++i)
    {
        ans += ar[i-l];
    }

    cout << ans << endl;

    return true;
}

int main()
{
    while(solve());
    return 0;
}

