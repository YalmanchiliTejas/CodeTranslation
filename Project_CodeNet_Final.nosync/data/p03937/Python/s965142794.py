H, W = map(int, input().split())
ban = [list(input()) for _ in range(H)]
cnt = 0
for i in range(H):
    for j in range(W):
        if ban[i][j] == "#":
            cnt += 1
if cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")