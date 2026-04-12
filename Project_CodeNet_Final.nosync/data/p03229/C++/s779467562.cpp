#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_WITH_SPACE(vector<ll> V)
{
    ll Vsize = V.size();
    for(int i=0;i<Vsize;i++)
    {
        cout << V[i];
        if(i!=Vsize-1)
        {
            cout << ' ';
        }
    }
    cout << endl;
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

ll Even(vector<ll> V)
{
    ll N = V.size();

    ll ans = 0;
    for(ll i=0;i<N;i++)
    {
        if(i<N/2-1) ans -= 2 * V[i];
        if(i==N/2-1) ans -= V[i];
        if(i==N/2) ans += V[i];
        if(i>N/2) ans += 2 * V[i];
    }
    return ans;
}

ll Odd(vector<ll> V)
{
    ll N = V.size();

    auto f = [N](vector<ll> V)
    {
        ll ans1 = 0;
        for(ll i=0;i<N;i++)
        {
            if(i<(N-1)/2-1) ans1 -= 2 * V[i];
            else if(i==(N-1)/2-1) ans1 -= V[i];
            else if(i==(N-1)/2) ans1 -= V[i];
            else ans1 += 2 * V[i];
        }

        ll ans2 = 0;
        for(ll i=0;i<N;i++)
        {
            if(i<(N-1)/2) ans2 -= 2 * V[i];
            else if(i==(N-1)/2) ans2 += V[i];
            else if(i==(N-1)/2+1) ans2 += V[i];
            else ans2 += 2 * V[i];
        }

        return max(ans1,ans2);
    };
    return f(V);
}

ll Ans(ll N, vector<ll> A)
{
    sort(ALL(A));

    if(N%2==0)
    {
        return Even(A);
    }
    else
    {
        return Odd(A);
    }
}

int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    ALLIN1_NUMBER(A);

    sort(ALL(A));

    OUT0(Ans(N,A));

    return 0;
}