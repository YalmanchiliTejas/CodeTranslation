from collections import Counter
import string
alpha = list(string.ascii_lowercase)
n = int(input())
s = []
words = []
for i in range(n):
    s.append(Counter(input()))
for i in alpha:
    now = float("inf")
    for j in range(n):
        now = min(now, s[j].get(i, 0))
    if now:
        words.append([i, now])
ans = []
for i in words:
    ans.append(i[0] * i[1])

print("".join(ans))