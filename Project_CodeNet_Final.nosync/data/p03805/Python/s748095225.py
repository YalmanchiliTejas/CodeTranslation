import sys 
from copy import deepcopy
from collections import deque
sys.setrecursionlimit(10**6)
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))

def solve(table,ava,now):
    if not 1 in ava:
        global ans
        ans += 1
        return
    global N
    for i in range(N):
        if table[now][i] and ava[i]:
            bt,ba = deepcopy(table),deepcopy(ava)
            bt[now][i] = bt[i][now] = ba[i] = 0
            solve(bt,ba,i)
    return

if __name__=='__main__':
    tmp = deque(LI())
    N,M = tmp.popleft(),tmp.popleft()
    table = [[0]*N for _ in range(N)]
    for i in range(M):
        tmp = deque(LI())
        a,b = tmp.popleft()-1,tmp.popleft()-1
        table[a][b] = table[b][a] = 1
    ans = 0
    ava = [1]*N
    ava[0] = 0
    solve(table,ava,0)
    print(ans)