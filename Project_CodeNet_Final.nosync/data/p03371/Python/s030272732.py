a,b,c,x,y = list(map(int, input().split()))

if a + b < 2*c :
    print(x*a + y*b)
else :
    if x >= y :
        if a >= 2*c:
            print(y*2*c + (x-y)*2*c)
        else :
            print(y*2*c + (x-y)*a)

    else :
        if b >= 2*c:
            print(x*2*c + (y-x)*2*c)
        else:
            print(x*2*c + (y-x)*b)


