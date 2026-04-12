import sys
H_W = list(map(int,input().split()))
H = H_W[0]
W = H_W[1]
b = [[0 for i in range(W)] for j in range(H)]
a = [[str(c) for c in l.strip()] for l in sys.stdin]

# .を0に, #を1にした新しい配列bを作る
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            b[i][j] = 1

# 列と行ごとにすべて0のものを探す
w = [0] * W
h = [0] * H
for i in range(H):
    for j in range(W):
        h[i] = h[i] + b[i][j]
        w[j] = w[j] + b[i][j]

#print(h)
#print(w)
# 全ての要素が0の列と行を削除する
i = 0
c = 0
j = 0
for i in range(H):
    if h[i] == 0:
        del a[j]
        H = H - 1
        j = j - 1
    j = j + 1
#print(a)

k = 0
for i in range(W):
    if w[i] == 0:
        for j in range(H):
            del a[j][k]
        W = W - 1
        k = k - 1
    k = k + 1
#print(a)
# 答え
for i in range(H):
    flag = 0
    for j in range(W):
        if flag == 0:
            ans = a[i][j]
            flag = 1
        else:
            ans = ans + a[i][j]
    print(ans)
    