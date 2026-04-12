import sys
INF = 10**10
MOD = 10**9 + 7
sys.setrecursionlimit(100000000)
from functools import lru_cache
from itertools import permutations

def main():
    n,m = map(int,input().split())
    dist = [[1] * n for _ in range(n)]
    for _ in range(m):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        dist[a][b] = 0
        dist[b][a] = 0
    
    cnt = 0
    for ptr in permutations(range(1,n)):
        flag = True
        if  dist[0][ptr[0]]:
            continue

        for i in range(n - 2):
            if dist[ptr[i]][ptr[i + 1]]:
                flag = False
                break
        
        if flag:
            cnt += 1
    
    print(cnt)

if __name__=='__main__':
    main() 