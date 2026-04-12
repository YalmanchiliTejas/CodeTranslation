def linecheck(a,i):
    for j in range(W):
        if a[i][j] != ".":
            return False
    return True
def colcheck(a,j,H):
    for i in range(H):
        if a[i][j] != ".":
            return False
    return True
H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(list(input()))
i = 0
while i<H:
    if linecheck(a,i):
        del a[i]
        i = 0
        H -= 1
    else:
        i += 1
j = 0
while j<W:
    if colcheck(a,j,H):
        for i in range(H):
            del a[i][j]
        j = 0
        W -= 1
    else:
        j += 1
for i in range(H):
    print("".join(a[i]))