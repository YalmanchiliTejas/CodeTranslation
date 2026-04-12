
from itertools import accumulate
def resolve():
    MOD = 10**9+7
    N = int(input())
    A = list(map(int, input().split()))

    Acc = [0] + list(accumulate(A))

    ans = 0
    for i in range(N):
        ans += A[i] * (Acc[N] - Acc[i+1])
        ans %= MOD

    print(ans)


if __name__ == "__main__":
    resolve()
