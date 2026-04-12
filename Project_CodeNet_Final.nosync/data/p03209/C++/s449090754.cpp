#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> num;
vector<ll> p;

ll findNum(int N, ll X)
{
    if(N==0)
        return 1;

    if(X==1)
        return 0;
    else if(X<=num[N]/2)
    {
        return findNum(N-1, X-1);
    }
    else if(X==(num[N]/2+1))
    {
        return 1+p[N-1];
    }

    return 1 + p[N-1] + findNum(N-1, X-2-num[N-1]);

}

int main()
{
    int N;
    ll X;
    cin>>N>>X;

    num.resize(50);
    p.resize(50);

    num[0] = 1;
    p[0] = 1;
    for(int i=0; i<50; ++i)
    {
        num[i+1]= 2 * num[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }

    ll ans = findNum(N, X);

    cout<<ans<<endl;


    return 0;
}
