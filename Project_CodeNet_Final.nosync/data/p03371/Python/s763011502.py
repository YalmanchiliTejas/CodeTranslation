a,b,c,x,y = map(int, input().split())

if a>= c*2 and b >= c*2:
    print(max(x,y)*c*2)

elif a>= c*2 and x>=y :
    print(x*c*2)

elif b >= c*2 and y>=x:
    print(y*c*2)

elif a + b < c*2:
    print(a*x+b*y)
    
elif a+b >= c*2:
    if x > y:
        print(y*c*2+(x-y)*a)
    else:
        print(x*c*2+(y-x)*b)