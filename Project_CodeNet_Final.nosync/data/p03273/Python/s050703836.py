h,w = map(int,input().split())
a = []
for i in range(h):
    b = input()
    if len(set(b)) > 1 or b[0] == '#':
        a.append(b)
c = list(range(w))
for i in range(w):
    f = 0
    for j in range(len(a)):
        if a[j][i] == '#':
            f = 1
            break
    if f == 0:
        c.remove(i)

for j in range(len(a)):
    for i in c:
        print(a[j][i],end = '')
    print('')
