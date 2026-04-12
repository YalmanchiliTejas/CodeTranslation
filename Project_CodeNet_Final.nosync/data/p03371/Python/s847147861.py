a,b,c,x,y = map(int, input().split())
ans1 = c * 2 * min(x,y) + a * (x-min(x,y)) + b * (y-min(x,y))
ans2 = a*x + b*y
ans3 = c * 2 * max(x,y)
print(min(ans1,ans2,ans3))