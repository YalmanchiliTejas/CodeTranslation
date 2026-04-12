from collections import defaultdict

n = int(input())
Ss = [input() for i in range(n)]
xs = []
for S in Ss:
    d = defaultdict(int)
    for s in S:
        d[s] += 1
    xs.append(d)

# cnt
a = ord("a")
alpha = [chr(i+a) for i in range(26)]
# print(alpha)
INF = 10**10
cnt = [INF] * 26
for x in xs:
    for i,s in enumerate(alpha):
        cnt[i] = min(x[s],cnt[i])

#答え
ans = ""
for i,s in enumerate(alpha):
    ans += s*cnt[i]
print(ans)
    