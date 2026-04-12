N,M = map(int,input().split())
G = [[0]*(N+1) for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    G[a][b] = 1
    G[b][a] = 1
    
import itertools
zero = [i for i in range(2,N+1)]
ans = 0
for i in itertools.permutations(zero,N-1):
    flag = 1
    if G[1][i[0]]!=1:
        flag = 0
    for j in range(len(i)-1):
        if G[i[j]][i[j+1]] != 1:
            flag = 0
    if flag == 1:
        ans += 1
print(ans)