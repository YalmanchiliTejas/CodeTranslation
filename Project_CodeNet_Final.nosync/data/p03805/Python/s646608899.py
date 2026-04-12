n, m = map(int,input().split())
A = [list(map(int,input().split())) for i in range(m)]

import itertools

M = [[0] * (n+1) for i in range(n+1)]
for i in range(m):
    M[A[i][0]][A[i][1]] = 1
    M[A[i][1]][A[i][0]] = 1

B = list(itertools.permutations(range(2, n+1)))

#print(B)

ans = 0
for i in range(len(B)):
    pt = 0
    if M[1][B[i][0]] == 1:
        pt += 1
    else:
        continue

    for j in range(len(B[i])-1):
        if M[B[i][j]][B[i][j+1]] == 1:
            pt += 1
    # print(B[i],pt)
    if pt == n-1:
        ans += 1
print(ans)
