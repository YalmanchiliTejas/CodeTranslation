h, w = map(int, input().split())

a = []
for i in range(h):
    s = input()
    if '#' in s:
        a.append(s)

b = [[a[x][y] for x in range(len(a))] for y in range(w)]
a = []
for x in b:
    if '#' in x:
        a.append(x)


for i in range(len(a[0])):
    for x in a:
        print(x[i], end='')
    print()
