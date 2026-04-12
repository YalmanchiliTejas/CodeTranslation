H,W = [int(zz) for zz in input().split()]
L = [list(input()) for _ in range(H)]

p = ['.']*W
while p in L:
    L.remove(p)
    H -= 1

L2 = [[0]*H for _ in range(W)]
for h in range(H):
    for w in range(W):
        L2[w][h] = L[h][w]


q = ['.']*H
while q in L2:
    L2.remove(q)
    W -= 1

ans = [[0]*W for _ in range(H)]
for h in range(H):
    for w in range(W):
        print(L2[w][h], end="")
    print()
