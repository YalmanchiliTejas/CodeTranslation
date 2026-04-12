from functools import reduce
from operator import and_
from collections import Counter
n = int(input())
S = [input() for _ in range(n)]
C = [Counter(s) for s in S]
s = sorted(reduce(and_, map(set, S), set(S[0])))
ans = "".join(si * min(c[si] for c in C) for si in s)
print(ans)
