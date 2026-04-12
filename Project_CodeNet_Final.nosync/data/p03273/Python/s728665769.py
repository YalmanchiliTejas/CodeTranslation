h,w = map(int,input().split())
A = [list(input()) for i in range(h)]
AH = []
AW = []
for i in range(h):
    if '#' in A[i]:
        AH.append(i)
for j in range(w):
    flag = 0
    for i in range(h):
        if A[i][j]=='#':
            flag = 1
    if flag:
        AW.append(j)
for i in AH:
    res = []
    for j in AW:
        res.append(A[i][j])
    print("".join(res))