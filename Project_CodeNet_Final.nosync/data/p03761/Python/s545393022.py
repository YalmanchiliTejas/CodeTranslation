from collections import Counter
n = int(input())
ans = ''
S = []
for _ in range(n):
    S.append(input())
S_sorted = sorted(list(set(S[0])))

for c in S_sorted:
    count = min(S[i].count(c) for i in range(n))
    ans += c * count

print(ans)

