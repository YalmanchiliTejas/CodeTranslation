N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

tmp = A[-1]
cum = [tmp]
for i in range(1, N-1)[::-1]:
    tmp += A[i]
    cum.append(tmp)
    
cum = cum[::-1]
ans = 0
for i in range(N-1):
    ans += cum[i]*A[i]
    ans %= mod

print(ans)