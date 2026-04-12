N = int(input())
A = list(map(int,input().split()))

B = [0]
b = 0

mod = 10**9 + 7

for i in range(N):
    b+=A[i]
    b%=mod
    B.append(b)

ans = 0

for i in range(N):
    ans += (mod+B[N]-B[i+1])*A[i]
    ans %= mod

print(ans)