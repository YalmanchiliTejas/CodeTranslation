N, M = [int(i) for i in input().split()]
road = [list() for i in range(N + 1)]
for i in range(M):
    a, b = [int(i) for i in input().split()]
    road[a].append(b)
    road[b].append(a)


def solve(before, visited, now):
    visited.append(now)
    if len(visited) is N:
        return 1
    pattern = 0
    for way in road[now]:
        if way is now:
            continue
        if way in visited:
            continue
        pattern += solve(now, visited[:], way)
    return pattern


print(solve(0, [], 1))
