height, width = map(int, input().split())

arr = []

for i in range(height):
    s = input()
    a = []
    for j in range(width):
        if s[j] == '#':
            a.append(1)
        else:
            a.append(0)
    arr.append(a)
    
h = 0
w = 0
f = 1

if arr[0][0] == 0:
    h = height-1
    w = width-1
    f = 0

while h < height-1 or w < width-1:
    if h == height-1:
        if arr[h][w+1] == 0:
            f = 0
            break
        else:
            arr[h][w+1] = 0
            w += 1
    elif w == width-1:
        if arr[h+1][w] == 0:
            f = 0
            break
        else:
            arr[h+1][w] = 0
            h += 1
    else:
        if arr[h][w+1] == 0:
            if arr[h+1][w] == 0:
                f = 0
                break
            else:
                arr[h+1][w] = 0
                h += 1
        else:
            if arr[h+1][w] == 1:
                f = 0
                break
            else:
                arr[h][w+1] = 0
                w += 1


if f == 0:
    print('Impossible')
else:
    extra = 0
    for i in range(height):
        for j in range(width):
            extra += arr[i][j]
    if extra > 1:
        print('Impossible')
    else:
        print('Possible')