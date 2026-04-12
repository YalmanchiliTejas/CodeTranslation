import itertools

N, M = map(int, input().split())

path = [[False] * N for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    path[a-1][b-1] = True
    path[b-1][a-1] = True

count = 0
for i in itertools.permutations(list(range(N)),N):
    if i[0] == 0:
        for j in range(N):
            if j == N-1:
                count += 1
                break
            if not path[i[j]][i[j+1]]:
                break
    

print(count)