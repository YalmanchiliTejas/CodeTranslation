h, w = map(int, input().split())
a = [''] * h
for i in range(h):
	a[i] = input()

tate = [False]*h
yoko = [False]*w

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            tate[i] = True
            yoko[j] = True

for i in range(h):
    if tate[i]:
        for j in range(w):
            if yoko[j]:
                print(a[i][j], end = '')
        print()