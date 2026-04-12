a,b,c,x,y  = map(int,input().split())
if a+b > c*2:
    mmm = min(x,y)
    aaa = max(x,y)
    if (x > y and a<=2*c):
        print(c*2*mmm + a*(aaa-mmm))
    elif (x > y and a>2*c):
        print(c*2*aaa)
    elif (x <= y and b<=2*c):
        print(c*2*mmm + b*(aaa-mmm))
    elif (x <= y and b>2*c):
        print(c*2*aaa)
else:
    print(a*x + b*y)
    