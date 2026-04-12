h, w = map(int, input().split())
mat_a = [ list(input()) for _ in range(h) ]

count = 0

ans = True
for i in range(h):
    for j in range(w):
        if mat_a[i][j] == '#':
            count+= 1

if count == h+w-1:
    print('Possible')
else:
    print('Impossible')