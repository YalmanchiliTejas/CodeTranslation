H,W = map(int,input().split())
a = []
index = []
for i in range(H):
    array = list(input())
    if list(set(array)) != ['.']:
        a.append(array)

h = len(a)
w = len(a[0])
for i in range(w):
    judge = False
    for j in range(h):
        if a[j][i] == '#':
            judge = True
    
    if not judge:
        index.append(i)

cnt = 0
for i in index:
    for j in range(h):
        del a[j][i-cnt]
    cnt += 1
for i in a:
    print(''.join(i))
    
