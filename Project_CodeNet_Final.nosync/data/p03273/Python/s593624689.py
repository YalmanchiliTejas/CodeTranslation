h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(input())

row = [0] * h
col = [0] * w

for i in range(h):
    if '#' in a[i]:
        row[i] = True

for i in range(h):
    for j in range(w):
        if '#' == a[i][j]:
            col[j] = True

for i in range(h):
    output = ''
    for j in range(w):
        if row[i] and col[j]:
            output += a[i][j]
    if not output == '':
        print(output)