# https://atcoder.jp/contests/abc054/tasks/abc054_c

from itertools import permutations

N,M = map(int, input().split())

edges = set()
for _ in range(M):
    a, b = map(int, input().split())
    edges.add((a,b))
    edges.add((b,a))



res = 0
for a in permutations(range(2,N+1),N-1):
    j = 1
    k = 0
    for i in a:
        if (j,i) in edges:
            k += 1
        if k == N-1:
            res += 1
        j = i

print(res)