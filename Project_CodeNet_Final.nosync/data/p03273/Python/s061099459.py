h, w = map(int, input().split())
A = ['']*h
for i in range(h):
    A[i] = input()

r = [False]*h
c = [False]*w
for i in range(h):
    for j in range(w):
        if A[i][j] == '#':
            r[i] = True
            c[j] = True

for i in range(h):
    if r[i]:
        for j in range(w):
            if c[j]:
                print(A[i][j], end='')
        print()