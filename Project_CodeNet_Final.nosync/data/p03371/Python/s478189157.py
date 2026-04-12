a,b,c,x,y=map(int,input().split())

if a+b <= c*2:
    print(a*x +b*y)
else:
    if x>y:
        i=a
    elif x<y:
        i=b
    else:
        i=0
    
    p=min(x,y)*c*2 + abs(x-y)*i
    q=max(x,y)*c*2
    
    if p >= q:
        print(q)
    else:
        print(p)