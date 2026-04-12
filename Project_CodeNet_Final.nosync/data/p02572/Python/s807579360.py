N = int(input())
A = list(map(int,input().split()))

sumA = sum(A)
MOD = 10 ** 9 + 7
ans = 0
for i in range(N):
    sumA -= A[i]
    ans += A[i] * sumA
    ans %= MOD
print(ans)