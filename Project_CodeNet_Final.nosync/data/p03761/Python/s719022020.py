N = int(input())
Ss = []
d = 97
for i in range(N):
    Ss.append(input())
from collections import Counter
counter = [float('inf') for i in range(26)]
for S in Ss:
    D = Counter(S)
    for key in range(d,d+26):
        counter[key-d] = min(D[chr(key)],counter[key-d])
ans = ''
for i,e in enumerate(counter):
    if e == float('inf'):
        continue
    for j in range(e):
        ans += chr(i+d)
print(ans)