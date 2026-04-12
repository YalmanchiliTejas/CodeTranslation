H, W = map(int, raw_input().split(' '))

M = []

for i in range(H):
    M.append(raw_input())

M2 = []

for i in range(H):
    if '#' in M[i]:
        M2.append(M[i])

idx = []
for i in range(W):
    flag = True
    for j in range(len(M2)):
        if M2[j][i] == '#':
            flag = False

    if flag == False:
        idx.append(i)

M3 = []
for i in range(len(M2)):
    s = ''
    for j in range(W):
        if j in idx:
            s += M2[i][j]
    M3.append(s)

print '\n'.join(M3)
