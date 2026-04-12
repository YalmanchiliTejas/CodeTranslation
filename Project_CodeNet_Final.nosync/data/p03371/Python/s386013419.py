a,b,c,x,y=map(int,input().split())
if c*2<a+b:
    if x<y:
        if c*2*max(x,y)>min(x,y)*c*2+b*(max(x,y)-min(x,y)):
            print(min(x,y)*c*2+b*(max(x,y)-min(x,y)))
        else:
            print(c*2*max(x,y))
    else:
        if c*2*max(x,y)>min(x,y)*c*2+a*(max(x,y)-min(x,y)):
            print(min(x,y)*c*2+a*(max(x,y)-min(x,y)))
        else:
            print(c*2*max(x,y))
else:
    print(a*x+b*y)
