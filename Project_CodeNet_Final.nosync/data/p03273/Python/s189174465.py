import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

H, W = map(int, readline().split())
# 行方向の除去…入力時に省く
# 列方向の除去…フラグを用意して、#が含まれている列のフラグを立てる
# 最終的にフラグが立っている列のみ出力
grid = []
black = [0] * W
for i in range(H):
    a = readline().decode().rstrip()
    if a.count('#') != 0:
        grid.append(a)
        for j in range(W):
            if a[j] == '#':
                black[j] = 1

# フラグが立っている列のみ文字列を結合していき、出力
for a in grid:
    s = ''
    for j in range(W):
        if black[j] == 1:
            s += a[j]
    print(s)
