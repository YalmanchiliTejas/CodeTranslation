N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
 
ans = 0
total = sum(A)
for i in range(N - 1):
    total -= A[i]
    ans += (A[i] * total) 
 
print(ans % mod)