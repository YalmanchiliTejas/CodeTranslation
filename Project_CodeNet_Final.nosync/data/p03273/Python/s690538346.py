H, W = map(int, input().split())
a = [input() for _ in range(H)]
temp = []
for i in range(H):
    if a[i] == ('.' * W):
        pass
    else:
        temp.append(a[i])
a = temp
temp = []
for i in range(W):
    flg = True
    for j in range(len(a)):
        if not a[j][i] == '.':
            flg = False
        if not flg:
            break
    else:
        temp.append(i)

for i in range(len(a)):
    for j in range(W):
        if j in temp:
            pass
        else:
            print(a[i][j], end='')
    print()
