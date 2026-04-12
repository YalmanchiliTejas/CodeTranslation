import collections
n = int(input())
s = [[] for _ in range(n)]
l = [collections.defaultdict(lambda:0) for _ in range(n)]
for i in range(n):
    s[i] = list(input())
    for j in s[i]:
        l[i][j] += 1
mind = [float("inf")]*26
for i in range(26):
    for j in range(n):
        mind[i] = min(mind[i],l[j][chr(97+i)])
ans = ""
for i in range(26):
    ans += chr(97+i)*mind[i]
print(ans)