import sys

input = sys.stdin.readline


def solve():
    MOD = 10**9+7
    N = int(input())
    A_L = tuple(int(x) for x in input().split())
    cum_a_l = [0] * N
    cum_a_l[0] = A_L[0]
    for i in range(1, N):
        cum_a_l[i] = (cum_a_l[i-1] + A_L[i]) % MOD
    ans = 0

    for i in range(N-1, 0, -1):
        ans = (ans + cum_a_l[i-1]*A_L[i] % MOD) % MOD
    print(ans)


solve()
