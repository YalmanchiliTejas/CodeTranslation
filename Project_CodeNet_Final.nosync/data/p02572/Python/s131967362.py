def cin():  return list(map(int,input().split()))

N = cin()[0]
A = cin()
S = sum(A)
INF = 10 ** 9 + 7
ans = 0
for i in range(N):
    S -= A[i]
    ans += A[i] * S
    ans %= INF
print(ans)