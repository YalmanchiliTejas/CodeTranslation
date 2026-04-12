H, W = [int(_) for _ in input().split()]
A = [input() for i in range(H)]

def solve(H, W, A):
    ssum = sum(row.count("#") for row in A)
    if ssum != H + W - 1:
        return False
    x, y = 0, 0
    if A[y][x] != "#":
        return False
    while 1:
        if y == H - 1 and x == W - 1:
            return True
        if (x + 1) < W and A[y][x + 1] == "#":
            x += 1
        elif (y + 1) < H and A[y + 1][x] == "#":
            y += 1
        else:
            return False

result = solve(H, W, A)

if result:
    print("Possible")
else:
    print("Impossible")
