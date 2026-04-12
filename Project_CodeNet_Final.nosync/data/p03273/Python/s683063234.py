#ABC107B
h,w = list(map(int,input().split()))
a = [0]*h
for i in range(h):
    a[i] = input()

h_d = []
for i in range(h):
    cnt = 0
    for j in range(w):
        if a[i][j] != '.':
            break
        cnt += 1
    if cnt == w:
        h_d.append(i)
a = [a[i] for i in range(h) if i not in h_d]

h_ = len(a)
w_d = []
for j in range(w):
    cnt = 0
    for i in range(h_):
        if a[i][j] != '.':
            break
        cnt += 1
    if cnt == h_:
        w_d.append(j)
a = [[a[j][i] for i in range(w) if i not in w_d]for j in range(h_)]

for i in range(h_):
    print(''.join(a[i]))