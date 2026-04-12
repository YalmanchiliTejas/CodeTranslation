import sys

def solve(N,M,E):
    def dfs(v, visited = set()):
        nonlocal cnt
        if len(visited) + 1 == N:
            cnt += 1
        for u in E[v]:
            if not u in visited:
                dfs(u, visited | {v})

    stack = [1]
    cnt = 0
    dfs(1)
    print(cnt)

def main():
    N, M = map(int, input().split())
    E = [ set() for _ in range(N+1) ]
    for _ in range(M):
        a, b = map(int, input().split())
        E[a].add(b)
        E[b].add(a)
    solve(N,M,E)

if __name__ == "__main__":
    main()