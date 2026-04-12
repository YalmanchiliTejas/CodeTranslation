N = int(input())
A = list(map(int,input().split()))
ans = 0
mod = 10**9 + 7
Sum = sum(A)

for i in range(N):
    Sum -= A[i]
    ans += Sum * A[i]
    ans = ans % mod
print(ans)
