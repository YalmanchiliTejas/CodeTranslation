H, W = (int(i) for i in input().split())
map = [list(input()) for i in range(H)]

count = 0
for h in range(H):
    for w in range(W):
        if map[h][w] == "#":
            count += 1
if count == H + W - 1:
    print("Possible")
else:
    print("Impossible")