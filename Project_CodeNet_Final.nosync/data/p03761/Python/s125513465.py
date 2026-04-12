from collections import Counter
n = int(input())
x = {i: 10000 for i in "abcdefghijklmnopqrstuvwxyz"}
for _ in range(n):
    s = Counter(input())
    for i in "abcdefghijklmnopqrstuvwxyz":
        x[i] = min(x[i], s[i])
ans = ""
for i, v in sorted(x.items()):
    ans += i * v
print(ans)