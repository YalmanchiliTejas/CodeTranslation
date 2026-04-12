a,b,c,x,y = [int(i) for i in input().split()]
chk = []
if x>y:
  chk.append(a*(x-y)+c*y*2)
  chk.append(c*x*2)
else:
  chk.append(b*(-x+y)+c*x*2)
  chk.append(c*y*2)
chk.append(a*x+b*y)
chk.append(a*x+c*y*2)
chk.append(c*x*2+b*y)
print(min(chk))