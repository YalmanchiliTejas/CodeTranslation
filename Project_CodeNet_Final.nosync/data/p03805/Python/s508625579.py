from collections import deque

N, M = [int(n) for n in input().split()]
n = [[] for _ in range(N)]

def dfs(p, done):
    curr = p[-1]
    nodes = n[curr]
    paths = list(set(nodes) - set(p))
    for path in paths:
        p.append(path)
        dfs(p, done)
    if not paths:
        done.append(list(p))
    del p[-1]
        
def main():
    for _ in range(M):
        a, b = map(lambda s: int(s) - 1, input().split())
        n[a].append(b)
        n[b].append(a)
    done = []
    p = deque([0])
    dfs(p, done)
    ans = sum(1 for li in done if len(li) == N)
    print(ans)

if __name__ == '__main__':
    main()