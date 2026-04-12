s = input()
n = len(s)
k = int(input())

dp = [[[0 for _ in range(2)] for _ in range(k + 1)] for _ in range(n + 1)]
dp[0][0][0] = 1

for l in range(n):
    for m in range(k + 1):
        for o in range(2):
            nd = int(s[l])
            for d in range(10):
                nl, nm, no = l + 1, m, o
                if d != 0:
                    nm += 1
                if nm > k:
                    continue
                if 0 == o:
                    if d > nd:
                        continue
                    if d < nd:
                        no = 1
                dp[nl][nm][no] += dp[l][m][o]
print(sum(dp[-1][-1]))
