a,b,c,x,y = map(int,input().split())
p = [a,b]
xy = [x,y]
if a+b <= c*2:
    print(a*x+b*y)
else:
    if p[xy.index(max(xy))] > c*2:
        print(c*2*max(xy))
    else:
        print(c*2*min(xy) + p[xy.index(max(xy))]*(max(xy)-min(xy))) 