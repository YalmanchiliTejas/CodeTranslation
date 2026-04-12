a,b,c,x,y=map(int,input().split())

ans1=a*x+b*y
ans2=c*2*x+b*(y-x) if y>=x else a*(x-y)+c*2*y
ans3=max(x,y)*2*c
print(min(ans1,ans2,ans3))