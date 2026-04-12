h,w = map(int,input().split())
a = [input() for i in range(h)]
a_count = 0
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            a_count += 1
if a_count == (h+w)-1:
    print('Possible')
else:
    print('Impossible')
