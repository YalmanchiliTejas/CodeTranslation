from collections import Counter

n = int(input())
s = Counter(input())
for _ in range(n-1):
    s &= Counter(input())
ans = ''.join(sorted([k*v for k, v in s.items()]))
print(ans)
