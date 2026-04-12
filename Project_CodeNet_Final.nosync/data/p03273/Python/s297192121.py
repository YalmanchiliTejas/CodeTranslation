h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]
y= 0
while y < h:
    x = 0
    flag = True
    while x < w:
        if a[y][x]=="#":
            flag = False
        x += 1
    if flag == True:
        a.pop(y)
        h -= 1
        y = 0
    else:
    	y += 1
x = 0
while x < w:
    y = 0
    flag = True
    while y < h:
        if a[y][x]=="#":
            flag = False
        y += 1
    if flag == True:
        for i in range(h):
            a[i].pop(x)
        w -= 1
        x = 0
    else:
    	x += 1

for i in a:
    ans = ''.join(i)
    print(ans)