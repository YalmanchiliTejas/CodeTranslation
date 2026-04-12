#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
//#define M 1000000007
#define N 100001
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll n, x, m;
unordered_map<int,int> M;     // value found -> at index
ll prefSum[N];
void printArray(int*, int);

int main() {
    scanf("%lld %lld %lld", &n, &x, &m);
    ll ans = x, curr, prev = x, i;
    prefSum[0] = x;     M[x] = 0;

    for(i=1; i<n; i++) {
        curr = (prev * prev) % m;

        if(M.find(curr) == M.end()) {
            M[curr] = i;
            prefSum[i] = curr + prefSum[i - 1];
            ans += curr;
        }
        else
            break;    

        prev = curr;
    }

    if(i != n) {
        ll rem = n - i;
        ll cycleLen = i - M[curr];
        ll cycleSum = (M[curr] == 0) ? prefSum[i - 1]: prefSum[i - 1] - prefSum[M[curr] - 1];

        ans += (rem / cycleLen) * cycleSum;
        
        rem = rem % cycleLen;
        ll extraSum = (M[curr] == 0) ? prefSum[rem - 1]: prefSum[M[curr] + rem - 1] - prefSum[M[curr] - 1];

        ans += extraSum;
    }

    printf("%lld\n", ans);
	return 0;
}

void printArray(int *nums, int n) {
    for(int i=0; i<n; i++) printf("%d ", nums[i]);
    printf("\n");
}