from collections import deque


def main():
    N, M = map(int, input().split())
    adj = [set() for _ in range(N)]
    for i in range(M):
        a, b = map(int, input().split())
        adj[a-1].add(b-1)
        adj[b-1].add(a-1)
    ans = 0
    q = deque([(0, set([0]))])
    while len(q):
        cur, visited = q.popleft()
        if len(visited) == N:
            ans += 1
            continue
        for nxt in adj[cur]:
            if nxt not in visited:
                nxtvst = set(visited)
                nxtvst.add(nxt)
                q.append((nxt, nxtvst))
    print(ans)


if __name__ == "__main__":
    main()
