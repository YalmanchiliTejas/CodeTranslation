from collections import Counter

n = int(input())
L = [Counter(str(input())) for _ in range(n)]
C = sorted(L[0])
ans = ''
for k in C:
    m = L[0][k]
    for i in range(n):
        m = min(m, L[i][k])
    ans += k * m
print(ans)
