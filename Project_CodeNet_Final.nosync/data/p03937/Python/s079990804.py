h, w = map(int, input().split())

a = [list(input()) for _ in range(h)]
cnt = 1
for x in range(h):
    for y in range(w):
        if a[x][y] == '#':
            cnt += 1
            

if cnt == h+w:
    print('Possible')
else:
    print('Impossible')