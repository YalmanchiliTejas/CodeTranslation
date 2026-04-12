n, x, m = map(int, input().split())
dp = [x]
s = set([x])
for i in range(1000000):
    if ((dp[-1] ** 2) % m) in s:
        dp.append((dp[-1] ** 2) % m)
        break
    s.add((dp[-1] ** 2) % m)
    dp.append((dp[-1] ** 2) % m)
ind = dp.index(dp[-1])
del dp[-1]
print(sum(dp[:ind]) + sum(dp[ind:]) * ((n - ind) // (len(dp) - ind)) + sum(dp[ind:ind + ((n - ind) % (len(dp) - ind))]))