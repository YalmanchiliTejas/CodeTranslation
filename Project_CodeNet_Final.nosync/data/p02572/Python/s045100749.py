N = int(input())
A = [int(i) for i in input().split()]
mod = 10**9+7
ans = 0
A_sum = sum(A)
for n in range(0,N-1):
    A_sum -= A[n]
    temp = A[n] * A_sum % mod
    ans += temp
    ans = ans % mod
print(ans)