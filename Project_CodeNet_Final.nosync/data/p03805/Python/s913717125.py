from itertools import permutations
n, m = map(int, input().split())
edges = {tuple(map(int, input().split())) for _ in range(m)}
ans = 0
for route in permutations(range(2, n+1)):
    route = [1] + list(route)
    ans += len([1 for edge in zip(route, route[1:])
                if tuple(sorted(edge)) in edges]) == n-1
print(ans)
