H, W = map(int, raw_input().split())
A = list()
for _ in range(H):
    A.append(list(raw_input()))

B = list()
for h in range(H):
    B.append(list())
    for w in range(W):
        B[h].append('.')

i = 0
j = 0
ret = "Impossible"
while True:
    B[i][j] = '#'
    # down and right
    if i+1 < H and j+1 < W:
        if A[i][j+1] == "#" and A[i+1][j] == ".":
            # right
            j += 1
        elif A[i][j+1] == "." and A[i+1][j] == "#":
            # down
            i += 1
        else:
            break
    # right only
    elif i+1 == H and j+1 < W:
        if A[i][j+1] == "#":
            # right
            j += 1
        else:
            break
    # down only
    elif i+1 < H and j+1 == W:
        if A[i+1][j] == "#":
            # down
            i += 1
        else:
            break
    elif i+1 == H and j+1 == W:
        if A == B:
            ret = "Possible"
        break
print ret