from collections import Counter

n = int(input())
l = [Counter(input()) for _ in range(n)]
c = Counter()

for s in [chr(97+i) for i in range(26)]:
    c[s] = 10**12
    for d in l:
        c[s] = min(c[s], d[s])

s = ""
for j in [chr(97+i) for i in range(26)]:
    s += j*c[j]
print(s)
