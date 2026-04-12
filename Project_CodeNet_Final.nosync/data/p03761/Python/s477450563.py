from collections import Counter

n = int(input())
ans = Counter(input())
for i in range(1, n):
    ans &= Counter(input())
print("".join(sorted(ans.elements())))
