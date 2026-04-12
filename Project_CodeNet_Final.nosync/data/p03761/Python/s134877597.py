# ABC0 C - 怪文書 / Dubious Document
from collections import defaultdict
si = lambda: input()
ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))

N = ni()
S = [input() for _ in range(N)]
ABC = set()
t = set()

for i,s in enumerate(S):
    if i == 0:
        for ss in s:
            ABC.add(ss)
            t.add(ss)
    else:
        ABC = ABC & t
        t = set()
        for ss in s:
            t.add(ss)
if len(ABC)==0:
    print('')
    exit()

ABC = list(ABC)
D = defaultdict(lambda: 10000)
for s in S:
    for abc in ABC:
        t = s.count(abc)
        D[abc] = min(t,D[abc])

ANS = ''
for k in D:
    ANS += k*D[k]

L = []
for ans in ANS:
    L.append(ans)

L.sort()
print(''.join(L))
