#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n , q , a , b;
int v[N];
bool ok[N];

int main()
{
    int curent = 1 , i;

    cin >> n >> q;

    ok[1] = ok[2] = 1;

    for(i = 1 ; i <= n ; i++)
        v[i] = i;

    for(i = 1 ; i <= q ; i++)
    {
        cin >> a >> b;

        if(curent == a)
            curent = b;
        else if(curent == b)
            curent = a;

        swap(v[a] , v[b]);

        if(curent > 1)
            ok[ v[curent - 1] ] = 1;

        if(curent < n)
            ok[ v[curent + 1] ] = 1;

        ok[ v[curent] ]= 1;
    }

    cout << count(ok + 1 , ok + n + 1 , 1);

    return 0;
}
