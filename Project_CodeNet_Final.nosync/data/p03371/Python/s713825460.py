a,b,c,x,y=map(int,input().split())
ans1=a*x+b*y
ans2=2*c*max(x,y)
ans3=2*c*min(x,y)+a*(x-min(x,y))+b*(y-min(x,y))
print(min(ans1,ans2,ans3))