from itertools import accumulate
def solve():
    N = int(input())
    A = list(map(int,input().split()))
    MOD = 10**9+7

    accm = list(accumulate(A))

    ans = 0
    for i in range(N-1,0,-1):
        ans += A[i] * accm[i-1] % MOD
        ans %= MOD

    print(ans%MOD)
        

if __name__ == '__main__':
    solve()
