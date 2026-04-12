from collections import Counter

N = int(input())
s = list(input())
c = Counter(s)

for _ in range(N - 1):
    s = list(input())
    tmp = Counter(s)
    for k, v in c.items():
        if k not in tmp:
            c[k] = 0
        else:
            c[k] = min(tmp[k], v)

ans = ""
c = sorted(c.items(), key=lambda x: x[0])
for k, v in c:
    ans += k * v
print(ans)
