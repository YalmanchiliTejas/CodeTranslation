a,b,c,x,y=map(int,input().split())
ans1=2*c*max(x,y)
ans2=2*c*min(x,y)+a*(x-min(x,y))+b*(y-min(x,y))
ans3=a*x+b*y
print(min(ans1,ans2,ans3))