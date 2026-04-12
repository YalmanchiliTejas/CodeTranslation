h,w = map(int,input().split())
a = [input() for i in range(h)]
ok = True
l = [False]*w
for i in range(h):
    d = False
    for j in range(w):
        if a[i][j]=='#':
            if i<h-1 and a[i+1][j]=='#':
                if d:ok=False
                d = True
            else:
                if l[j]: ok=False
                l[j] = True
print('Possible' if ok else 'Impossible')