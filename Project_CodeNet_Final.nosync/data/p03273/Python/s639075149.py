h, w = map(int, input().split())
a = [''] * h
for i in range(h):
    a[i] = input()
# print(a)

# 行、列に黒が存在するならTrue
row = [False] * h
col = [False] * w
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            row[i] = True
            col[j] = True
# print(row)
# print(col)

for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                # 一つずつprintすると改行されてしまう
                # end="" で改行しないようにする
                print(a[i][j], end='')
        print()  # print() で改行、次のrowへ