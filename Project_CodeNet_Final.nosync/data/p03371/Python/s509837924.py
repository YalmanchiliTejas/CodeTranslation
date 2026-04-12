a,b,c,x,y=map(int,input().split())
cnta=0
cntb=0
cntab=0
if a+b>=2*c:
    cntab=2*min(x,y)
    if x>=y:
        if a>=2*c:
            cntab+=2*(x-y)
        else:
            cnta=x-y
    else:
        if b>=2*c:
            cntab+=2*(y-x)
        else:
            cntb=y-x
            cnta=0          
else:
    cnta=x
    cntb=y

print(a*cnta+b*cntb+c*cntab)