import sys,queue,math,copy,itertools,bisect,collections,heapq

def main():
    sys.setrecursionlimit(10**7)
    INF = 10**18
    MOD = 10**9 + 7
    LI = lambda : [int(x) for x in sys.stdin.readline().split()]
    NI = lambda : int(sys.stdin.readline())

    N,M = LI()
    root = [[] for _ in range(N)]
    for _ in range(M):
        a,b = LI()
        root[a-1].append(b-1)
        root[b-1].append(a-1)
    node = [0] * N

    ans = 0
    q = []
    q.append((0,1))

    while q:
        u,d = q.pop()
        if d < 0:
            node[u] = 0
        else:
            node[u] = d
            q.append((u,-1))
            for v in root[u]:
                if node[v]: continue
                if d+1 == N: ans += 1
                else:
                    q.append((v,d+1))

    print(ans)

if __name__ == '__main__':
    main()