a,b,c,x,y=map(int,input().split())
sum=0
m=min(x,y)
if(a+b>2*c):
    sum+=2*c*m
else:
    sum+=x*a+b*y
    print(sum)
    exit()
s=0
z=0
if x>y:s=a
else: s=b
sum+=min(2*c,s)*max(x-m,y-m)
print(sum)