n = int(input())
a = list(map(int, input().split()))

inf = float('inf')

# 累積和
if n % 2 == 0:
    l_even = [0]
    l_odd = [0]
    for i in range(n):
        if i % 2 == 0:
            l_even.append(l_even[-1] + a[i])
        else:
            l_odd.append(l_odd[-1] + a[i])
    ans = -inf
    for i in range(n // 2 + 1):
        if ans < l_even[i] + l_odd[-1] - l_odd[i]:
            ans = l_even[i] + l_odd[-1] - l_odd[i]
    print(ans)
    exit()

# dp[i] = i回ずらしを使った時の最大値
# 1個ずつdpを更新
# i = 0, 1, 2
dp = [a[0], a[1], a[2]]
for i in range(2, n-2, 2):
    dp[2] = max([dp[2] + a[i+2], dp[1] + a[i+2]])
    dp[1] = max([dp[1] + a[i+1], dp[0] + a[i+1]])
    dp[0] += a[i]

print(max(dp))