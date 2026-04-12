import sys

aa = input().strip().split()
h = int(aa[0])
w = int(aa[1])
a = [list(input().strip()) for _ in range(h)]
r = [list() for _ in range(2)]

for i in range(h):
    if a[i][0] == '.':
        flag = True

        for j in range(1, w):
            if a[i][j] != '.':
                flag = False
                break

        if flag:
            r[0].append(i)

for i in range(w):
    if a[0][i] == '.':
        flag = True

        for j in range(1, h):
            if a[j][i] != '.':
                flag = False
                break

        if flag:
            r[1].append(i)

for i in reversed(range(len(r[0]))):
    del a[r[0][i]]

for i in reversed(range(len(r[1]))):
    for j in reversed(range(len(a))):
        del a[j][r[1][i]]

for i in range(len(a)):
    for j in range(len(a[i])):
        sys.stdout.write(a[i][j])

    sys.stdout.write('\n')
