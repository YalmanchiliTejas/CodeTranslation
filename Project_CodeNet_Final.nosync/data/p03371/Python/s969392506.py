a,b,c,x,y = list(map(int,input().split()))
output = 10000000000
if x > y:
  tmp = (y * min(a+b,c*2)) + ((x-y) * min(a,c*2))
  if output > tmp:
    output = tmp
else:
  tmp = (x * min(a+b,c*2)) + ((y-x) * min(b,c*2))
  if output > tmp:
    output = tmp

print(output)