H, W = map(int, input().split())
X = [[1 if a == "#" else 0 for a in input()] for _ in range(H)]

Q = [0]
D = [[0] * W for _ in range(H)]
D[0][0] = 1
while Q:
    x = Q.pop()
    i, j = x//W, x%W
    for di, dj in ((1, 0), (0, 1)):
        ni, nj = i+di, j+dj
        if ni < H and nj < W and X[ni][nj]:
            if D[ni][nj] == 0:
                D[ni][nj] = 1
                Q.append(ni*W + nj)
if D[-1][-1] and sum([sum(x) for x in X]) == H + W - 1:
    print("Possible")
else:
    print("Impossible")