N = int(input())
S = [input() for i in range(N)]
from collections import Counter
ctr = Counter(S[0])
for s in S[1:]:
    ctr &= Counter(s)
ans = ''
for k,v in sorted(ctr.items()):
    ans += k * v
print(ans)