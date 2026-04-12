MOD = 10**9 + 7

import time

def solve(N, A):
    ans = 0
    asum = sum(A)
    for i in range(N-1):
        asum -= A[i]
        ans = (ans + A[i] * asum) % MOD
    return ans

if __name__ == '__main__':
    N = int(input())
    A = [int(a)%MOD for a in input().split()]
    ans = solve(N, A)
    print(ans)