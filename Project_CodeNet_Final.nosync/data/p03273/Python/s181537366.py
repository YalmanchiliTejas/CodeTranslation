#b1:マス目の初期状態
H,W = map(int,input().split())
b = [[0 for i in range(W)] for j in range(H)]
for i in range(0,H):
    line = input()
    for j in range(0,W):
        b[i][j] = line[j]
        
#全て白の行を見つける
x = []
for k in range(0,H):
    flag = True
    for k2 in range(W):
        if b[k][k2] is '#':
            flag = False
    if flag:
        x.append(k)
#全て白の列を見つける
y = []
for l in range(W):
    flag = True
    for m in range(H):
        if b[m][l] is '#':
            flag = False
    if flag:
        y.append(l)

#全て白の行と列を除いたマス目を作る
b2 = [[0 for i in range(W-len(y))] for j in range(H-len(x))]
c1,c2 = 0,0
for i in range(H):
    c2 = 0
    if i not in x:
        for j in range(W):
            if j not in y:
                b2[c1][c2]=b[i][j]
                c2 += 1
        c1 += 1

#表示
for i in range(H-len(x)):
    s = ""
    for j in range(W-len(y)):
        s += b2[i][j]
    print(s)
        