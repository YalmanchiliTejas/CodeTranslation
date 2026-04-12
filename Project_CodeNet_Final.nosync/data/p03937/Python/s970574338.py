H, W = map(int, input().split())
A = [input() for _ in range(H)]
s = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            s += 1

if s == H + W - 1:
    print("Possible")
else:
    print("Impossible")
