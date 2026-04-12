h, w = [int(x) for x in input().split()]
A = []
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

#　後ろ側から  列削除フラグが 1 の列を削除
for j in range(w)[::-1]:
    if rm_pos[j] == 1:
        for i in range(len(A)):
            del A[i][j]

# 回答出力
for i in range(len(A)):
    print(''.join(A[i]))