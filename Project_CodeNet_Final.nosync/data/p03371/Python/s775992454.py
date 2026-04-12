a,b,c,x,y = map(int,input().split())

ans = 0
ans += min(x,y)*min(a+b,2*c)
if y > x:
  ans += (y-x)*min(b,c*2)
if x > y:
  ans += (x-y)*min(a,c*2)
print(ans)