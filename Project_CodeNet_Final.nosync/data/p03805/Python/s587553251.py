from collections import deque

def main():
    ans = 0
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        ai, bi = map(int, input().split())
        for j in range(1, N+1):
            if ai == j:
                graph[j-1].append(bi)
            elif bi == j:
                graph[j-1].append(ai)
        
    q = deque()
    q.append([1, {_ for _ in range(2, N+1)}])

    while q:
        prev, exist = q.popleft()

        if not exist:
            ans += 1
        for next in exist:
            if next in graph[prev-1]:
                q.append([next, exist-{next}])

    print(ans)

if __name__ == "__main__":
    main()

