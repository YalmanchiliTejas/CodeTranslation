a,b,c,x,y = map(int,input().split())
if x>y:
  a,b,x,y = b,a,y,x
res = a*x +b*y
for i in range(x):
  p_res = res
  res += 2*c-(a+b)
  if p_res<res:
    res = p_res
    break
for i in range(y-x):
  p_res = res
  res += 2*c-b
  if p_res < res:
    res = p_res
    break
print(res)