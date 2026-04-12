H,W = map(int,input().split())
A = [list(input()) for _ in range(H)]
B = [[0 for _ in range(W)] for _ in range(H)]
for i in range(H):
    for j in range(W):
        if A[i][j]=="#":
            B[i][j] = 1
C = []
for i in range(H-1,-1,-1):
    if sum(B[i])==0:
        C.append(i)
B1 = []
for i in range(H):
    if i not in C:
        B1.append(B[i])
C = []
for j in range(W):
    flag = 0
    for i in range(len(B1)):
        if B1[i][j]==1:
            flag = 1
            break
    if flag==0:
        C.append(j)
B2 = []
for i in range(len(B1)):
    row = []
    for j in range(W):
        if j not in C:
            row.append(B1[i][j])
    B2.append(row)
B3 = []
for i in range(len(B2)):
    x = ""
    for j in range(len(B2[i])):
        if B2[i][j]==0:
            x += "."
        else:
            x += "#"
    B3.append(x)
for i in range(len(B3)):
    print(B3[i])