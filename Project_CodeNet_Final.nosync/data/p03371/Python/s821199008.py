a,b,c,x,y = map(int, input().split())

ans1 = c*max(x,y)*2
ans2 = a*x + b*y
if x<y:
    ans3 = c*2*x + b*(y-x)
else:
    ans3 = c*2*y + a*(x-y)

print(min(ans1,ans2,ans3))
