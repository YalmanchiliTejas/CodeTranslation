from collections import Counter, defaultdict

alp = list("abcdefghijklmnopqrstuvwxyz")

n = int(input())
INF = 100
d = defaultdict(lambda: INF)

for i in range(n):
    s = input()
    count = Counter(s)
    for k in alp:
        d[k] = min(d[k], count[k])

# print(d)
ans = ""
for k in alp:
    if d[k] == 0:
        continue
    ans += k * d[k]
print(ans)
