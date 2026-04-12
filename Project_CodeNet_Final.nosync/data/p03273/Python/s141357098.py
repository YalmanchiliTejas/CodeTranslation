h, w = map(int, input().split())
a = [input() for i in range(h)]
b = [['0']*w for i in range(h)]
for i in range(w):
    cnt = 0
    for j in range(h):
        if a[j][i] == '.':
            cnt += 1
    if cnt != h:
        for p in range(h):
            b[p][i] = a[p][i]
for i in range(len(b)):
    b[i] = [j for j in b[i] if j != '0']
for i in b:
    if ''.join(i) != '.'*len(i):
        print(''.join(i))