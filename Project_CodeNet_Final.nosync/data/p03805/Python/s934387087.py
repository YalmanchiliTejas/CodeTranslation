import itertools
N, M = [int(n) for n in input().split()]
path = [[False for i in range(N)]for j in range(N)]


for i in range(M):
    a, b = [int(n)-1 for n in input().split()]
    path[a][b] = True
    path[b][a] = True


res = 0
for way in itertools.permutations(range(1,N), N-1):
    exist = True
    if path[0][way[0]] == False:
        exist = False
    for n in range(N-2):
        if path[way[n]][way[n+1]] == False:
            exist = False
    if exist == True:
        res += 1

print(res)
