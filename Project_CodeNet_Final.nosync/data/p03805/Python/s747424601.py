import itertools
N, M = map(int ,input().split())
matrix = [[0]*N for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    matrix[a-1][b-1] = 1
    matrix[b-1][a-1] = 1

count = 0

for p in itertools.permutations(range(N)):
    #print(p)
    if p[0] != 0:
        break
    check = 1
    for s in range(N-1):
        check = check  * matrix[p[s]][p[s+1]]
    count += check

print(count)