h, w = map(int, input().split())

count = 0
for i in range(h):
    a = list(input())
    for j in range(w):
        if a[j] == '#':
            a[j] = 1
        else:
            a[j] = 0
    count += sum(a)
    
if count == w + h - 1:
    print('Possible')
else:
    print('Impossible')