import itertools

N, M = map(int, input().split(" "))
edge = [[False]*N for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split(" "))
    edge[a-1][b-1] = True
    edge[b-1][a-1] = True

ans = 0

for i in itertools.permutations(range(1,N)):
    P = (0,) + i
    flag = True
    for j in range(len(P)-1):
        if edge[P[j]][P[j+1]] == False:
            flag = False
            break
    if flag:
        ans += 1

print(ans)