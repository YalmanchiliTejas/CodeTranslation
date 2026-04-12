from itertools import permutations
n, m = map(int, input().split())
edges = {tuple(map(int, input().split())) for _ in range(m)}

ans = 0
for i in permutations(range(2, n+1), n-1):
    load = [1]+list(i)
    ans += sum(1 for edge in zip(load, load[1:])
               if tuple(sorted(edge)) in edges) == n-1
print(ans)
