h, w = [int(x) for x in input().split()]
A = []
rm_pos = []

for i in range(h):
    a = input()
    if a != '.' * w:
        A += [list(a)]

flg = True

# 白マスのみの列 検索
for j in range(w):
    for i in range(len(A)):
        if A[i][j] != '.':
            flg = False
            break
    if flg == True:
        rm_pos += [j]
    flg = True
rm_pos = reversed(rm_pos)

# 列の削除
for j in rm_pos:
    for i in range(len(A)):
        del A[i][j]


# 回答出力
for i in range(len(A)):
    print(''.join(A[i]))