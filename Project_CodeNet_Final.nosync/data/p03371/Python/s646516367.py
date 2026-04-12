a,b,c,x,y = map(int,input().split())
if x>y:
    w1,w2 = (a+b)*y, c*2*y
    d1,d2 = a*(x-y), c*2*(x-y)
    print(min(w1+d1, w1+d2, w2+d1, w2+d2))
else:
    w1,w2 = (a+b)*x, c*2*x
    d1,d2 = b*(y-x), c*2*(y-x)
    print(min(w1+d1, w1+d2, w2+d1, w2+d2))