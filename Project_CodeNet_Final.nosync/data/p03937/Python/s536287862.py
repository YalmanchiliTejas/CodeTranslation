H,W = (int(i) for i in input().split())
A = []
for i in range(H):
    A.append(input())

numright = 0
numdown = 0
for i in range(H):
    now = A[i][0]
    for j in range(1,W):
        if now == "#" and A[i][j] == "#":
            numright += 1
        now = A[i][j]

for i in range(W):
    now = A[0][i]
    for j in range(1,H):
        if now == "#" and A[j][i] == "#":
            numdown += 1 
        now = A[j][i]

#print(numdown,numright)
if numdown == H - 1 and numright == W - 1:
    print("Possible")
else:
    print("Impossible")            