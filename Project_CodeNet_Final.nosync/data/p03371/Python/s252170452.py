a,b,c,x,y = map(int, input().split())

piza = a*x+b*y
if min(x,y)==x:
  if piza > c*2*x + b*(y-x): piza = c*2*x + b*(y-x)
  if piza > c*2*y: piza = c*2*y
else:
  if piza > c*2*y + a*(x-y): piza = c*2*y + a*(x-y)
  if piza > c*2*x: piza = c*2*x
print(piza)