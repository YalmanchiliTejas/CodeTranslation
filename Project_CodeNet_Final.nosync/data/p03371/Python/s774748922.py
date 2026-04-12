a,b,c,x,y = map(int,input().split())

ans = [0,0,0]
ans[0] = a*x + b*y
ans[1] = max(x,y)*2*c

if x < y:
  ans[2] += x*2*c
  ans[2] += b*(y-x)
else:
  ans[2] += y*2*c
  ans[2] += a*(x-y)
print(min(ans))