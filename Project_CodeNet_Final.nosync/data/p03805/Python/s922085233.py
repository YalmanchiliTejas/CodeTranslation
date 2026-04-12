import itertools
import collections

n, m = map(int, input().split())

a = [list(sorted(map(int, input().split()))) for i in range(m)]
a.sort()

cnt = 0

#2,...,nの順列を表すイテレータ
for i in itertools.permutations(range(2, n + 1), (n - 1)):
    li = [1] + list(i)
    #順列を経路とみなし、実際に辺が存在するかをcheck.辺の本数がn-1となればよい.
    if sum(list(sorted(edge)) in a for edge in zip(li, li[1:])) == n - 1:
        cnt += 1

print(cnt)
