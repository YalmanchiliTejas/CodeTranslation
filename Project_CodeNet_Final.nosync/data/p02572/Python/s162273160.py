n = int(input())
lst = list(map(int, input().split()))
mod = 10**9+7

# 累積和(Cumulative sum)リストの作成
cumsum = [0]*(n+1)
for i in range(n):
    cumsum[i+1] = lst[i] + cumsum[i]

# 題意より、lst の1つ前までが対象
ans = 0
for i in range(n-1):
    ans += (cumsum[n] - cumsum[i+1]) * lst[i]
print(ans % mod)
