#include <bits/stdc++.h>

using namespace std;

int n;
int v[200001];
int a[200001];

int main()
{
    cin >> n;

    int i;
    for(i = 1; i <= n; i ++)
        cin >> v[i], a[i] = v[i];

    sort(v + 1, v + n + 1);

    for(i = 1; i <= n; i ++)
    {
        if(n % 2)
        {
            int poz = (n + 1) / 2;

            if(a[i] >= v[poz])
                cout << v[poz - 1] << "\n";

            else
                if(a[i] < v[poz])
                    cout << v[poz] << "\n";
        }

        else
        {
            int poz = (n + 1) / 2;

          //  cout << poz << " " << v[poz] << " " <<

            if(a[i] > v[poz])
                cout << v[poz] << "\n";

            else
                if(a[i] <= v[poz])
                    cout << v[poz + 1] << "\n";
        }
    }

    return 0;
}
