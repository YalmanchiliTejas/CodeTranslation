from   itertools import   permutations

N,M = map(int, input().split())
L = [list(map(int,input().split())) for _ in range(M)]
graph = [[False] * (N + 1) for _ in range(N + 1)]
#%%

for i in L:
    graph[i[0]][i[1]] = True
    graph[i[1]][i[0]] = True

graph[0][1] = True
graph[1][0] = True
#%%
ans = 0
for i in permutations(range(1, N + 1)):
    if i[0] != 1:
        continue
    for j in range(1, N):
        if not graph[i[j - 1]][i[j]]:
            break
    else:
       ans += 1 

print(ans)
