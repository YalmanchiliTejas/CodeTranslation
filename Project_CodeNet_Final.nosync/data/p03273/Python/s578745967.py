h, w = map(int, input().split())
a = []
H = [0]*h
W = [0]*w
for i in range(h):
    a.append(input())

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            H[i] += 1
            W[j] += 1

for i in range(h):
    if H[i] != 0:
        for j in range(w):
            if W[j] != 0:
                print(a[i][j], end = '')
        print()