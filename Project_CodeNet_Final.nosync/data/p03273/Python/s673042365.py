h, w = [int(x) for x in input().split()]
A = []
B = []

# 列削除用フラグ初期化 1で削除
rm_pos = [1]*w

# 白マスのみの行はリスト追加しない
for i in range(h):
    a = input()
    if a != '.' * w:
        A += [list(a)]

# 白マスのみの列 検索、. が含まれていない場合は 削除フラグを0に
for j in range(w):
    for i in range(len(A)):
        if A[i][j] != '.':
            rm_pos[j] = 0 
            break

#  del list を使わず
#　列削除フラグが 0 の列のみ新規リストへ追加

for i in range(len(A)):
    tmp = []
    for j, flg in enumerate(rm_pos):
        if flg == 0:
            tmp += A[i][j]
    B += [tmp]

# 回答出力
for i in range(len(B)):
    print(''.join(B[i]))