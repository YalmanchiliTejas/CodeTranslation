import sys
input = sys.stdin.readline

H, W = map(int, input().split())
L = [list(input().strip()) for _ in range(H)]

for i in range(H):
    if "#" not in L[i]:
        for j in range(i, H):
            L[i] = [None] * W
            
for i in range(W):
    f = True
    for j in range(H):
        if L[j][i] == "#":
            f = False
            break
    if f:
        for j in range(H):
            L[j][i] = None
            
for i in range(H):
    f = False
    for j in range(W):
        if L[i][j] != None:
            print(L[i][j], end = "")
            f = True
    if f:
        print()