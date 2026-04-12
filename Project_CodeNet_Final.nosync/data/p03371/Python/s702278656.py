a,b,c,x,y=map(int,input().split())
ans1=a*x+b*y
ans2=0
ans3=max(x,y)*2*c

if x==y:
    ans2=c*x*2
elif x>y:
    ans2=c*y*2
    ans2+=a*(x-y)
else:
    ans2=c*x*2
    ans2+=b*(y-x)

print(min(ans1,ans2,ans3))