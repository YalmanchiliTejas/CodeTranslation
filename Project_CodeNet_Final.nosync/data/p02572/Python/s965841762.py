def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    MOD = 10**9+7
    total = sum(A)%MOD
    ans = 0
    for i in range(N):
        total -= A[i]
        total %= MOD
        ans += A[i]*total
        ans %= MOD
    print(ans)
    


if '__main__' == __name__:
    resolve()