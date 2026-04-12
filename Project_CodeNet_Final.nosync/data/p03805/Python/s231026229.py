N, M = map(int, input().split())
r = [set() for _ in range(N+1)]
for _ in range(M):
    n1, n2 = map(int, input().split())
    r[n1].add(n2)
    r[n2].add(n1)

from itertools import permutations as p
c = 0
kumis = p(range(2, N+1))
for kumi in kumis:
    prev = 1
    for k in kumi:
        if k not in r[prev]:
            break
        prev = k
    else:
        c += 1
print(c)