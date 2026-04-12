a,b,c,x,y = map(int, input().split())

if 2*c >= a+b: 
    print(a*x + b*y) # buy separately
else:
    if max(x,y) == x:
        if a <= 2*c:  print((x-y)*a + y*2*c)
        else:         print(x*2*c)
            
    else: # max(x,y) == y
        if b <= 2*c:  print((y-x)*b + x*2*c)
        else:         print(y*2*c)