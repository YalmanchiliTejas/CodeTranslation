from collections import deque

def solve():
    ret = 0
    stack = deque()
    stack.append([1, {1}])
    while stack:
        node, used = stack.popleft()
        if len(used) == N:
            ret += 1
            continue

        for n in neighbors[node]:
            if n in used:
                continue
            stack.append([n, used | {n}])

    print(ret)

if __name__ == "__main__":
    N, M = map(int, input().split())
    neighbors = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b = map(int, input().split())
        neighbors[a].append(b)
        neighbors[b].append(a)
    solve()