h, w = map(int, input().split())
a =[]
for i in range(h):
    row = list(input())
    if '#' in row:
        a.append(row)
    else:
        h -= 1
num = []
for i in range(w):
    for j in range(h):
        if a[j][i] == '#':
            num.append(i)
            break
    
for i in range(h):
    for j in num:
        print(a[i][j],end = '')
    print()