from itertools import permutations

N,M = map(int,input().split())

mat = [[0 for i in range(N)] for j in range(N)]

for _ in range(M):
    a,b = map(int,input().split())
    mat[a-1][b-1] = 1
    mat[b-1][a-1] = 1

ans = 0
for i in permutations(range(N)):
    if i[0] != 0:
        continue
    else:

        flag = True
        for j in range(N-1):
            if not mat[i[j]][i[j+1]]:##つながってない
                flag = False
                break
        if flag:
            ans += 1 

print(ans)