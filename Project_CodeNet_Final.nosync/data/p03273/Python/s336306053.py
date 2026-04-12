# B - Grid Compression
H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

# 横方向を調べる
for i in reversed(range(H)):
        if a[i].count(".") == W:
            a.pop(i)

# 抜けた分、縦の長さを再定義する
H = len(a)

# 縦方向を調べる
for i in reversed(range(W)):
    for j in range(H):
        if a[j][i] == ".":
            pass
        else:
            break
    else:
        for j in range(H):
            a[j].pop(i)

# 出力
for i in range(H):
    a[i] = "".join(a[i])
    print(a[i])
