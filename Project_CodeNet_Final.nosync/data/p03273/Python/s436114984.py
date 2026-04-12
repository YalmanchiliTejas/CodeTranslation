s = input().split()

h = int(s[0])
w = int(s[1])

line = []
row = []

a = [''] * h

for i in range(h):
    a[i] = input()

for i in range(h):
    line.append(False)
for i in range(w):
    row.append(False)

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            line[i] = True
            row[j] = True

for i in range(h):
    if line[i]:
        for j in range(w):
            if row[j]:
                print(a[i][j], end='')
        print('')

