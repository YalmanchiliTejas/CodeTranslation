h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
b = ['.'] * w

while b in a:
    a.remove(b)

for i in range(w):
    flag = True
    for j in a:
        if j[i] == '#':
            flag = False
            break
    if flag:
        for j in a:
            j[i] = ''

for i in a:
    print(''.join(i))