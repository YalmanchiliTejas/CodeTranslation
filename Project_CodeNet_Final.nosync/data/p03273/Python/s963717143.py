H,W = map(int,input().split())
A = [list(input().strip()) for _ in range(H)]

for i in range(H-1,-1,-1):
    ind = 0
    for j in range(W):
        if A[i][j]!=".":
            ind = 1
            break
    if ind==0:
        A.pop(i)
for j in range(len(A[0])-1,-1,-1):
    ind = 0
    for i in range(len(A)):
        if A[i][j]!=".":
            ind = 1
            break
    if ind==0:
        for i in range(len(A)):
            A[i].pop(j)
for i in range(len(A)):
    x = ""
    for j in range(len(A[i])):
        x += str(A[i][j])
    print(x)