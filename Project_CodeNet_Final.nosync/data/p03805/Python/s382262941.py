(n,m), *ab = [list(map(int, s.split())) for s in open(0)]

from collections import defaultdict

d = defaultdict(list)

for a,b in ab:
    d[a] += [b]
    d[b] += [a]

def count_paths(passed, cur, d, n):
#     print(f'{passed=}, {cur=}')
    if len(passed) == n-1:
        return 1
    ans = 0
    for nx in d[cur]:
        if nx not in passed:
            ans += count_paths(passed+[cur], nx, d, n)
    return ans

print(count_paths([],1,d,n))