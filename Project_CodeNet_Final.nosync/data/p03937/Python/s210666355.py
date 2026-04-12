# マンハッタン距離のように移動
# H + W - 1 ならPossible

H,W = map(int,input().split())

cnt = 0
for _ in range(H):
    cnt += list(input()).count("#")

if cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")