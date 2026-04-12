#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N);
    int count = 1;

    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    for(int i = 1; i < N; i++)
    {
        bool flag = true;
        for(int j = 0; j < i; j++)
        {
            if(H[j] > H[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)count++;
    }
    cout << count << endl;
}