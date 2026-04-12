H,W = map(int,input().split())
list = [input() for i in range(H)]
del_H = []
del_W = []

for h in range(H):
    if list[h] == '.'*W:
        del_H.append(h)

for w in range(W):
    list_C = []
    for h in range(H):
        list_C.append(list[h][w])
        if ''.join(list_C) == '.'*H:
            del_W.append(w)

list_new = []

for h in range(H):
    list_join = []
    if h in del_H:
        continue
    for w in range(W):
        if w in del_W:
            continue
        list_join.append(list[h][w])
    join_w = ''.join(list_join)
    list_new.append(join_w)

for i in list_new:
    print(i)