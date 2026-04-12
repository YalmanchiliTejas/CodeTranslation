a,b,c,x,y = map(int,input().split())
A_B = a*x+b*y
AB = 2*c*max(x,y)
A_AB = 10**11
AB_B = 10**11
if x-y > 0:
  A_AB = a*(x-y)+2*c*y
if y-x > 0:
  AB_B = 2*c*x+b*(y-x)

ans = min(A_B,A_AB,AB_B,AB)
print(ans)
