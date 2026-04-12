N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

tmp_sum = sum(A)
ans = 0
for i in range(N-1):
    tmp_sum -= A[i]
    ans += tmp_sum*A[i]

print(ans%mod)