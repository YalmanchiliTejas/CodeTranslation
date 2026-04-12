a,b,c,x,y = map(int,input().split())
if 2*c >= a+b:
    print(a*x+b*y)
else:
    if x>= y:
        count = c*2*y
        count += min(c*2*(x-y),a*(x-y))
        print(count)
    else:
        count = c*2*x
        count += min(c*2*(y-x),b*(y-x))
        print(count)