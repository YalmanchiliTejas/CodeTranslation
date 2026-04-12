n = int(input())
aaa = list(map(int, input().split()))
mod = 1000000007
c_sum = [0] * n
c_sum[n - 1] = aaa[n - 1]
ans = 0

for i in range(n - 2, 0, -1):
    c_sum[i] = (c_sum[i + 1] + aaa[i]) % mod

for i in range(n - 1):
    ans += aaa[i] * c_sum[i + 1] % mod
    ans %= mod

print(ans)