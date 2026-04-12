import itertools
n, m = map(int, input().split())
e = set([tuple(sorted(map(int, input().split()))) for x in range(m)])
cnt = 0
for i in itertools.permutations(range(2, n+1), n-1):
    l = [1]+list(i)
    if sum(1 for x in range(n-1) if tuple(sorted(l[x: x+2])) in e) == n-1:
        cnt += 1
print(cnt)