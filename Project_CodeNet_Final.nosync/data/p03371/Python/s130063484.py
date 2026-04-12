def compare(q,p):
    if q>p:
        return p
    else:
        return q
a,b,c,x,y= map(int, input().split())
re=0
if a+b>2*c:
    if x>y:
        re=compare(c*x*2,c*y*2+a*(x-y))
    else:
        re=compare(c*y*2,c*x*2+b*(y-x))
else:
    re=a*x+b*y
print(re)