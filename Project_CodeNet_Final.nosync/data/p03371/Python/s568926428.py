a,b,c,x,y = [int(i) for i in input().split()]

maxxy = max([x,y])
price = 0

prices=[]

for i in range(maxxy+1):
  amai = x-i
  bmai = y-i
  
  if amai<0:
    amai = 0
  if bmai<0:
    bmai = 0
  
  price = i*2*c + amai*a + bmai*b
  prices.append(price)
  
print(min(prices))
  
  
  