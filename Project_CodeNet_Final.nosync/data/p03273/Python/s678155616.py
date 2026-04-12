h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]
y =0;x=0
while y < h:
    flag = True
    for x in range(w):
        if a[y][x]=='#':
            flag = False
    
    if flag == True:
        a.pop(y)
        h -= 1
        y = 0
    else:
    	y += 1
x = 0 
while x < w:
    flag = True
    for y in range(h):
        if a[y][x]=='#':
            flag = False
    
    if flag == True:
        for s in range(h):
            a[s].pop(x)
        w -= 1
        x = 0
    else:
        x += 1
            
for i in range(h):
    print(''.join(a[i]))