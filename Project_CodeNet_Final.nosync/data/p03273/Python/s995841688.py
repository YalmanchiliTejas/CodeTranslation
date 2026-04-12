# 初期入力 2020-0730-2150

import sys
input = sys.stdin.readline  #文字列では使わない
H,W = map(int, input().split())
a =[]
for h in range(H):
    *aa, =input().strip()
    a.append(aa)

x =["."]*W
del_h =[]
for h in range(H):
    if a[h] ==x:
        del_h.append(h)

y =["."]*H
del_w =[]
for w in range(W):
    d =[]
    for h in range(H):
        if a[h][w] ==".":
            d.append(".")
    if d ==y:
        del_w.append(w)

for i in range(H):
    if i in del_h:
        continue
    for j in range(W):
        if j in del_w:
            continue
        print(a[i][j],end="")
    print()