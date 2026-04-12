H, W = [int(_) for _ in input().split()]
l = []
del_list_H = []
del_list_W = []
for i in range(H):
    l.append(list(input()))

for i in range(H):
    t = 0
    for j in range(W):
        if l[i][j] == '.':
            t += 1
    if t == W:
        del_list_H.append(i)

counter = len(del_list_H)
for i in range(counter):
    del l[del_list_H[i]]
    del_list_H = [x-1 for x in del_list_H]
    H -= 1

for i in range(W):
    t = 0
    for j in range(H):
        if l[j][i] == '.':
            t += 1
    if t == H:
        del_list_W.append(i)

counter = len(del_list_W)
for i in range(counter):
    for j in range(H):
        del l[j][del_list_W[i]]
    del_list_W = [x-1 for x in del_list_W]
    W -= 1


for i in range(len(l)):
    text = ''
    for j in range(len(l[i])):
        text += l[i][j]
    print(text)
