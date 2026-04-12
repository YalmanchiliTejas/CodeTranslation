H,W = map(int,input().split())
a = [""] * H #空白のリスト
for i in range(H):
    a[i] = input()

row = [False] * H #真偽値の2次元配列
col = [False] * W
for i in range(H):
    for j in range(W):
        if a[i][j] == "#": #一つでも#があれば真
            row[i] = True
            col[j] = True

for i in range(H):
    if row[i]:
        for j in range(W):
            if col[j]:
                print(a[i][j],end="")

        print()
