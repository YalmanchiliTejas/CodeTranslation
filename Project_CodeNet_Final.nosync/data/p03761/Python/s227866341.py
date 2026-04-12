n = int(input())
s = [list(input()) for _ in range(n)]
alluse = set(s[0])
for i in range(1, len(s)):
    alluse = alluse & set(s[i])
res = ""
alluse = sorted(alluse)
for c in alluse:
    count = 100
    for i in range(n):
        count = min(count, s[i].count(c))
    res += c*count
print(res)
