# 値の取得
H, W = map(int, input().split())
# 配列の準備
A = []
# #がある列のみをAについか
for i in range(H):
    a = list(input())  # 一文字ずつに分割されたリストなる
    if '#' in a:
        A.append(a)
    else:
        H = H - 1
# .のみの行を削除
for i in range(W - 1, -1, -1):  # rangeはiの値をfor文中でいじっても変更不可
    ch = 0
    for j in range(H):
        if A[j][i] == '#':
            ch = 0
            break
        else:
            ch = 1
    if ch == 1:
        for k in range(H):
            del A[k][i]
# 出力
for i, a in enumerate(A):
    print(''.join(a))
