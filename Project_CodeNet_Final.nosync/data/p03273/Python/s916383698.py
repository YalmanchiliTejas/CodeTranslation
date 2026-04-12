y, x = map(int, input().split())
r = [True] * y
c = [True] * x
z = []
for i in range(y):
    a = input()
    z.append(a)
    for j in range(x):
        if '#' == a[j]:
            c[j] = False
            r[i] = False
for i in range(y):
    if r[i] == False:
        for j in range(x):
            if c[j] == False:
                print(z[i][j], end='')
        print()
        