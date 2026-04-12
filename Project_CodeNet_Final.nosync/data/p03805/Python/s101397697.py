from collections import deque


def main():
    N, M = map(int, input().split())
    adj = [[False] * N for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        adj[a][b] = True
        adj[b][a] = True
    retval = 0
    q = deque([(0, set([0]))])
    while len(q):
        cur, visited = q.popleft()
        if len(visited) == N:
            retval += 1
            continue
        for nxt in range(N):
            if nxt in visited:
                continue
            if adj[cur][nxt]:
                next_visited = set(visited)
                next_visited.add(nxt)
                q.append((nxt, next_visited))
    print(retval)


if __name__ == "__main__":
    main()
