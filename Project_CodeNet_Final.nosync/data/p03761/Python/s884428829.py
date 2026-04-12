from collections import Counter

n = int(input())

s = Counter(list(input()))
for i in range(n-1):
    s &= Counter(list(input()))

ans = ""
for i, j in sorted(s.items()):
    ans += i*j

print(ans)