from itertools import permutations

N,M = map(int,input().split())

edge = [[0 for i in range(N)] for j in range(N)]

for _ in range(M):
    a,b = map(int,input().split())
    edge[a-1][b-1] = 1
    edge[b-1][a-1] = 1

ans = 0
for path in permutations(range(N)):
    flag = True
    if path[0] != 0:
        flag = False
    for i in range(N-1):
        if not edge[path[i+1]][path[i]]:
            flag = False
    
    ans += int(flag)

print(ans)