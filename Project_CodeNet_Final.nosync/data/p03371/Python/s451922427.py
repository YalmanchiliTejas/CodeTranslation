a,b,c,x,y = map(int,input().split())

count = 0

ans1 = a*x + b*y
ans2 = 2*c*(min(x,y))
ans3 = 2*c*(max(x,y))

if x > y:
  ans2 += a*(x-y)
elif x < y:
  ans2 += b*(y-x)

print(min(ans1,ans2,ans3))