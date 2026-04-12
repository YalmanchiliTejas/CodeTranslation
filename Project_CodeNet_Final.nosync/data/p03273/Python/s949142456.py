H,W = map(int,input().split())
A = []
for i in range(H):
    a = list(input())
    if a.count('.') == W:
        H -= 1
        continue
    A.append(a)

skipcol = []
for i in range(W):
    t = 0
    for j in range(H):
        if A[j][i] == '.':
            t += 1
    if t == H: skipcol.append(i)

for i in range(H):
    for j in range(W):
        if j in skipcol: continue
        print(A[i][j],end='')
    print()