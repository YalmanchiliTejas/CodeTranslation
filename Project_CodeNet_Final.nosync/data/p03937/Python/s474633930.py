H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

no = "Impossible"
h, w = 0, 0
while h < H-1 or w < W-1:
    if A[h][w] == ".":
        print(no)
        break
    A[h][w] = "."
    if h > 1:
        if A[h-1][w] == "#":
            print(no)
            break
    if w > 1:
        if A[h][w-1] == "#":
            print(no)
            break
    
    if h < H-1:
        if A[h+1][w] == "#":
            h += 1
            continue

    if w < W-1:
        if A[h][w+1] == "#":
            w += 1
            continue

else:
    A[H-1][W-1] = "."
    for i in range(H):
        if A[i].count("#") > 0:
            print(no)
            break
    else:
        print("Possible")
