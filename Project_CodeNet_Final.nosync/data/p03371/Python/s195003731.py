a,b,c,x,y=map(int,input().split())
l=sorted([a,b,c*2])
if l[0]==c*2:
    print(max(x,y)*c*2)
elif l[1]==c*2:
    if l[0]==a:
        print(y*c*2+max((x-y),0)*a)
    else:
        print(x*c*2+max((y-x),0)*b)
else:
    if a+b>=c*2:
        if x>=y:
            print(y*2*c+(x-y)*a)
        else:
            print(x*2*c+(y-x)*b)
    else:
        print(x*a+y*b)