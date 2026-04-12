#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

bool can(li nOps, vector<li> a)
{
    int n = a.size();
    li buffer = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        a[i] += nOps;
        if (a[i] >= (n - 1))
            buffer += (a[i] - (n - 1)) / (n + 1) + 1;
        if (buffer >= nOps) return true;
    }
    return buffer >= nOps;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<li> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    unsigned long long answer = 0;
    while (true)
    {
        sort(a.rbegin(), a.rend());
        
        int r = 0;
        while (r + 1 < n && a[0] - a[r + 1] <= n) r++;
        
        // group [0, r] will have cyclic evolutions with period (r+1):
        // down by n-r in (r+1) steps
        
        if (r == n - 1)
        {
            //printf("OK\n");
            li can_steps = a[0] - 1000;
            if (can_steps > 0)
            {
                answer += (can_steps) * (unsigned long long)(r + 1);
                for (int i = 0; i < n; i++)
                    a[i] -= can_steps;
                continue;
            }
        }
        else
        {
            li down = n - r;
            // a[r] - down * steps - 3 * n <= a[r + 1] + steps * (r + 1)
            
            li steps = (a[0] - a[r + 1]) / (down + r + 1);
            steps -= 100;
            //printf("%lld\n", steps * (li)(r + 1));
            
            if (steps > 0)
            {
                for (int i = 0; i <= r; i++)
                    a[i] -= steps * (li)(n - r);
                for (int i = r + 1; i < n; i++)
                    a[i] += steps * (li)(r + 1);
                
                answer += steps * (unsigned long long)(r + 1);
                continue;
            }
        }
        
        if (a[0] < n) break;
        
        a[0] -= n;
        for (int k = 1; k < n; k++)
            a[k]++;
        
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}
