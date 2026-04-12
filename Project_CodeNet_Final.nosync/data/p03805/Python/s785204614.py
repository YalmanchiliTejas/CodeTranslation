from itertools import permutations

n, m = map(int, input().split())

edges = {tuple(sorted(map(int, input().split()))) for _ in range(m)}
ans = 0

for i in permutations(range(2,n+1), n-1):
    l = [1] + list(i)
    tmp = sum(1 for edge in zip(l, l[1:]) if tuple(sorted(edge)) in edges) == n-1
    ans += tmp
print(ans)

