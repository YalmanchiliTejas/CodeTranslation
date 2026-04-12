from sys import stdin

H, W = [int(i) for i in stdin.readline().rstrip().split()]
a = [stdin.readline().rstrip() for _ in range(H)]

del_row = []

for i in range(len(a)):
    all_while = True
    s = a[i]
    for c in s:
        if c == '#':
            all_while = False
            break
    if all_while:
        del_row.append(i - len(del_row))

for i in del_row:
    a.pop(i)

a_t = []
for col in range(W):
    s = ''
    for row in range(len(a)):
        s += a[row][col]
    a_t.append(s)

del_row = []

for i in range(len(a_t)):
    all_while = True
    s = a_t[i]
    for c in s:
        if c == '#':
            all_while = False
            break
    if all_while:
        del_row.append(i - len(del_row))

for i in del_row:
    a_t.pop(i)

a = []
for col in range(len(a_t[0])):
    s = ''
    for row in range(len(a_t)):
        s += a_t[row][col]
    a.append(s)

for i in a:
    print(i)
