from itertools import permutations

N, M = map(int, input().split())
matrix = [[0] * N for i in range(N)]
ans = 0

for i in range(M):
    a, b = map(int, input().split())
    matrix[a-1][b-1] = 1
    matrix[b-1][a-1] = 1
    

for order in list(permutations(range(N))):
    if order[0] != 0:
        break
        
    check = 1
    for i in range(N-1):
        check *= matrix[order[i]][order[i+1]]
    ans += check
    
print(ans)