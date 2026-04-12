#include <bits/stdc++.h>
using namespace std;

int A[100005], tree[400005];
map<int, int> M;

void update(int left, int right, int x, int val, int root)
{
    if(left > x || right < x)
        return;
    
    if(left == right)
    {
        tree[root] = val;
        return;
    }

    int mid = (left + right) / 2;

    update(left, mid, x, val, root*2);
    update(mid+1, right, x, val, root*2+1);

    tree[root] = max(tree[root*2], tree[root*2+1]);
}

int query(int left, int right, int L, int R, int root)
{
    if(left > R || right < L)
        return 0;
    
    if(left >= L && right <= R)
        return tree[root];
    
    int mid = (left + right) / 2;

    return max(query(left, mid, L, R, root*2), query(mid+1, right, L, R, root*2+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        cin >> A[i];
        M[ A[i] ];
    }

    int k = 0;

    for(auto &it : M)
        it.second = ++k;
    
    for(int i=1; i<=N; i++)
        A[i] = M[ A[i] ];
    
    int ans = 0;

    for(int i=1; i<=N; i++)
    {
        int curr = query(1, k, A[i], k, 1) + 1;
        update(1, k, A[i], curr, 1);
        ans = max(ans, curr);
    }

    cout << ans << "\n";
    return 0;
}
