a,b,c,x,y=map(int,input().split())
p1=a*x+b*y
min=10**9
for i in range(10**5+1):
    p2=2*i*c+max(0,x-i)*a+max(0,y-i)*b
    if p2<min:
        min=p2
if min<p1:
    print(min)
else:
    print(p1)