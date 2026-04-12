N = int(input())
A = list(map(int, input().split()))
ans = 0
mod = pow(10,9)+7

B = []
x = 0
for i in range(N-1):
    x += A[i]
    x %= mod
    B.append(x)

ans = 0
for i in range(1,N):
    ans += A[i]*B[i-1]
    ans %= mod

print(ans)
