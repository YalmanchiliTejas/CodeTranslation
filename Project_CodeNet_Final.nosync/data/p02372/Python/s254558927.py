from heapq import heappush, heappop

def input(f):
    n, = map(int, f.readline().split())
    s = [None for _ in range(n-1)]
    t = [None for _ in range(n-1)]
    w = [None for _ in range(n-1)]
    for i in range(n-1):
        s[i], t[i], w[i] = map(int, f.readline().split())
    return n, s, t, w

def solve(n, s, t, w):
    graph = [[] for _ in range(n)]
    def add_edge(src, dst, w):
        graph[src].append((dst, w))
        graph[dst].append((src, w))
    for i in range(n-1):
        add_edge(s[i], t[i], w[i])
    
    queue = []
    
    def find(root):
        INF = 100000 * 1000 + 1;
        best = [INF for _ in range(n)]
        best[root] = 0
        
        def find_next(cur):
            for nxt_v, nxt_w in graph[cur]:
                dist = best[cur] + nxt_w
                if dist < best[nxt_v]:
                    best[nxt_v] = dist
                    yield dist, nxt_v
        
        def dequeue():
            _, cur_v = heappop(queue)
            for nxt in find_next(cur_v):
                heappush(queue, nxt)
        
        while queue:
            dequeue()

        res = (0, root)
        for i in range(n):
            if best[i] > res[0]:
                res = (best[i], i)
        return res, best
    
    def run(root):
        heappush(queue, (0, root))
        return find(root)
    
    ret0, best0 = run(0)
    ret1, best1 = run(ret0[1])
    ret2, best2 = run(ret1[1])
    
    for i in range(n):
        yield max(best1[i], best2[i])

with open('/dev/stdin') as f:
    for d in solve(*input(f)):
        print(d)
