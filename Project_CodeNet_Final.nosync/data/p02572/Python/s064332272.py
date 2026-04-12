mod = 10**9+7
N = int(input())
A = list(map(int, input().split()))
Ar = list(reversed(A))
for i in range(1,N):
    Ar[i] += Ar[i-1]
ans = 0
Ar = list(reversed(Ar))
for i in range(N-1):
    ans += A[i]*Ar[i+1]
    ans %= mod
print(ans)