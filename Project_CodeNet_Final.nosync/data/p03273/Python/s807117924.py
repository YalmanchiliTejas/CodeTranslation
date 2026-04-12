h, w = map(int, input().split())
a = []
for i in range(h):
    tmp = list(input())
    a.append(tmp)
H = [0] * h
W = [0] * w

b = list(zip(*a))

for i in range(h):
    if a[i].count('#') != 0:
        H[i] = 1

for i in range(w):
    if b[i].count('#') != 0:
        W[i] = 1

c = []
for i in range(h):
    tmp = []
    for j in range(w):
        if H[i] == 1 and W[j] == 1:
            tmp.append(a[i][j])
    if tmp != []:
        c.append(tmp)

for i in range(len(c)):
    print(''.join(c[i]))