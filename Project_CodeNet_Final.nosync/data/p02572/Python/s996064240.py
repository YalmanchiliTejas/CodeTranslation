n = int(input())
lst = list(map(int, input().split()))
mod = 10**9+7

# 累積和リストの作成
sums = [0]*(n+1)
for i in range(n):
    sums[i+1] = lst[i] + sums[i]

# 題意より、lst の1つ前までが対象
ans = 0
for i in range(n-1):
    ans += (sums[n] - sums[i+1]) * lst[i]
print(ans % mod)
