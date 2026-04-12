n = int(input())
arr_a = list(map(int, input().split()))

mod = 10**9 + 7
memo = {}

for i in range(n):
    if i == 0:
        memo[n-i-1] = 0
    else:
        memo[n-i-1] = (memo[n-i] + arr_a[n-i]) % mod

ans = 0
for i in range(n):
    ans += arr_a[i] * memo[i]
    ans = ans % mod

print(ans)
