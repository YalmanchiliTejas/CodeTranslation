import sys
read_=sys.stdin.buffer.readline

a,b,c,x,y=map(int,read_().split())

ans1=x*a+y*b
if max(x,y)==x:
    ans2=y*c*2+(x-y)*a
else:
    ans2=x*c*2+(y-x)*b
ans3=max(x,y)*2*c

print(min(ans1,ans2,ans3))