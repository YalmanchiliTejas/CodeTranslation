H,W = map(int,input().split())
A = []
for i in range(H):
    a = list(input())
    if "#" in a:
        A.append(a)
    else:
        H -= 1
for j in range(W-1,-1,-1):
    for i in range(H):
        if A[i][j] == "#":
            break
        elif i == H - 1:
            for k in range(H):
                del A[k][j]
for e in A:
    print("".join(e))