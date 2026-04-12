a,b,c,x,y = map(int,input().split())

if a+b > 2*c:
  if x <= y:
    ans = x*c*2 + (y-x)*min(b,2*c)
  elif y < x:
    ans = y*c*2 + (x-y)*min(a,2*c)
    
else:
  ans = x*a + y*b
  
print(ans)