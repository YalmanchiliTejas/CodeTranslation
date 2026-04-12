n = int(input())
alp = 'abcdefghijklmnopqrstuvwxyz'
S1 = input()
from collections import Counter
SC1 = Counter(S1)

for a in alp:
    SC1.setdefault(a, 0)

for _ in range(n-1):
    S = input()
    SC = Counter(S)
    for a in alp:
        SC.setdefault(a, 0)
        SC1[a] = min(SC1[a], SC[a])

ans = ''
for a in alp:
    ans += a*SC1[a]
print(ans)
