h, w = map(int, input().split())
a = []
for i in range(h):
    x = input()
    if x == '.'*w:
        continue
    a.append(list(x))

for i in range(w):
    t = True
    length = len(a)
    for j in range(length):
        if a[j][i] != '.':
            t = False
            break
    if t:
        for k in a:
            k[i] = 'D'


for i in a:
    for j in i:
        if j != 'D':
            print(j, end='')

    print()
