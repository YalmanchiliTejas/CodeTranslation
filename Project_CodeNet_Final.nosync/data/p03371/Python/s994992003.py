a,b,c,x,y=map(int,input().split())
ans1=a*x+b*y
if x>=y:
    ans2=a*(x-y)+c*y*2
    ans3=c*x*2
else:
    ans2=b*(y-x)+c*x*2
    ans3=c*y*2
print(min(ans1,ans2,ans3))