a,b,ab,x,y=map(int,input().split())
total=0
if a+b>2*ab:
    total+=min(x,y)*2*ab
    if x>y:
        x-=y
        if a>=2*ab:
            total+=2*ab*x
        else:
            total+=a*x
    elif x<y:
        y-=x
        if b>=2*ab:
            total+=2*ab*y
        else:
            total+=b*y
else:
    total+=a*x+b*y
print(total)