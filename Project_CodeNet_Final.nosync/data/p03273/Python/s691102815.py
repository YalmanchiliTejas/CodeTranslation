h,w = map(int, input().split())

a = [['x'] * w for i in range(h)]
for i in range(h):
    tmp = list(str(input()))
    for j in range(w):
        a[i][j] = tmp[j]


for i in range(h):
    flag = True
    for j in range(w):
        if a[i][j] == '#':
            flag = False

    if flag:
        for j in range(w):
            a[i][j] = 'x'

arr = []
for i in range(h):
    if a[i][0] == 'x':
        pass
    else:
        arr.append(a[i])


s = [len(v) for v in arr]
h = len(s)
w = s[0]

for i in range(w):
    flag = True
    for j in range(h):
        if arr[j][i] == '#':
            flag = False

    if flag:
        for j in range(h):
            arr[j][i] = 'x'

for i in range(h):
    for j in range(w):
        if arr[i][j] != 'x':
            print(arr[i][j], end='')
    print('')
