N = int(input())
A = list(map(int,input().split()))
ans = 0
mod = 1000000007

a = sum(A)

for i in range(N):
    a -= A[i]
    ans += A[i]*a
    ans %= mod

print(ans)