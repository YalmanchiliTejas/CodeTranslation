N = int(input())
A = list(map(int, input().split()))

mod = 0
for i in range(N):
    mod += A[i]%(10**9+7)

ans = (mod*mod)%(10**9+7)
for i in range(N):
    ans -= A[i]*A[i]
    ans = ans%(10**9+7)
ans = ans*pow(2, -1, 10**9+7)
ans = ans %(10**9+7)
print(ans)

