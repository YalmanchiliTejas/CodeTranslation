H,W = map(int,input().split())

a = [list(input()) for i in range(H)]

not_removedH = []#捨てない行
for i in range(H):
    removed = True
    for j in range(W):
        if a[i][j]=="#":#一つでも黒があれば終わり
            removed = False
            break
    if not removed:
        not_removedH.append(i)

not_removedW = []#捨てない列
for j in range(W):
    removed = True
    for i in range(H):
        if a[i][j]=="#":
            removed = False
            break
    if not removed:
        not_removedW.append(j)


#捨てる列を削除していく
for i in range(H):
    tmp = []
    for j in not_removedW:
        tmp.append(a[i][j])
    a[i]=tmp

for i in not_removedH:
    print("".join(a[i]))
