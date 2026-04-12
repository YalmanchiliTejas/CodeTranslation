H,W = map(int,input().split())
grid = []
for h in range(H):
    a = input()
    if '#' in a: #行がすべて白の行ははじめから除く
        grid.append(a)

white = set() #圧縮する列の数字を格納
for w in range(W):
    if all(l[w] == '.' for l in grid): #グリッドの列ごとに走査
        white.add(w)

for l in grid:
    print("".join(l[w] for w in range(W) if w not in white)) 