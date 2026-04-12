H, W = list(map(int,input().split()))
A = [list(input()) for _ in range(H)]
NA = []
for a in A:
    if '#' in a:
        NA.append(a)
for i in range(W):
    ydel = True
    for j in NA:
        if j[i] == '#':
            ydel = False
            break
    if not ydel:
        continue
    for j in NA:
        j[i] = 'D'
for na in NA:
    nna = []
    for i in na:
        if i != 'D':
            nna.append(i)
    print(''.join(nna))