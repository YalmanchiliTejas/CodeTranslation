n,m=map(int,input().split())

path = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    path[a].append(b)
    path[b].append(a)

def solve(route):
    if len(route) == n:
        return 1
    count = 0
    for i in path[route[-1]]:
        if i in route: continue
        count += solve(route + [i])
    return count

print(solve([0]))