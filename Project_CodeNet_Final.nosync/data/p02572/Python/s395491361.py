N = int(input())
A = list(map(int, input().split()))
Total = []
mod = 10**9+7
c = 0
for i in range(N):
    c += A[i]
    Total.append(c)

ans = 0
for i in range(N):
    k = Total[-1] - Total[i]
    ans += A[i]*k % mod
    ans = ans % mod
print(ans % mod)