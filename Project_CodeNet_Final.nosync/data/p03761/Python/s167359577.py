from collections import Counter

n = int(input())

a = input()
c = Counter(a)

for _ in range(1, n):
    x = input()
    cx = Counter(x)

    for string, count in c.items():
        c[string] = min(count, cx[string])

ans = []
for string, count in c.items():
    ans += [string] * count

ans.sort()
print("".join(ans))