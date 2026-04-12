n = list(map(int, input().split()))
H, W = n[0], n[1]
li = [['.' for i in range(W)] for i in range(H)]

for i in range(H):
    l = input()
    for j in range(len(l)):
        li[i][j] = l[j]

pos = []
# horizontal check
for i in range(H):
    c = 0
    for j in range(W):
        if li[i][j] == '.':
            c += 1
    if c == W:
        pos.append(i)

j = 0
for i in range(len(pos)):
    li.pop(pos[i]-j)
    j += 1


pos = []
# vertical check
for i in range(len(li[0])):
    c = 0
    for j in range(len(li)):
        if li[j][i] == '.':
            c += 1
    if c == len(li):
        pos.append(i)

for i in range(len(li)):
    m = 0
    for x in range(len(pos)):
        li[i].pop(pos[x]-m)
        m += 1

for i in range(len(li)):
    print("".join(li[i]))
