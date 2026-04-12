h, w = map(int, input().split())
a = []
for i in range(h):
    s = input()
    if s.count('.') != w:
        a.append(s)
b = []
for i in range(w):
    f = True
    for x in a:
        if x[i] != '.':
            f = False
    if f:
        b.append(i)
for x in a:
    for i in range(len(x)):
        f = True
        for j in b:
            if i == j:
                f = False
        if f:
            print(x[i], end='')
    print()