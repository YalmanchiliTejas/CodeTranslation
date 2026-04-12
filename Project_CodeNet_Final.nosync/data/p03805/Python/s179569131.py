from collections import deque
from copy import copy as dc
import sys

def main():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    ab = [list(map(int, input().split())) for i in range(m)]
    g = [[] for i in range(n+1)]
    for i in ab:
        g[i[0]].append(i[1])
        g[i[1]].append(i[0])
    que = deque()
    que.append([1,-1,0,set([1])])
    ans = 0
    while que:
        v, p, cnt, check = que.popleft()
        if cnt >= n - 1:
            if len(check) == n:
                ans += 1
            continue
        for nv in g[v]:
            if nv == p:
                continue
            a = dc(check)
            a.add(nv)
            que.append([nv, v, cnt+1, a])
    print(ans)

if __name__ == "__main__":
    main()
