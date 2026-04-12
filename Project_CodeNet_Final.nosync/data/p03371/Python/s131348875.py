A,B,C,X,Y=map(int,input().split(' '))

price=[]
for i in range(100001):
  price.append(2*C*i+A*max([X-i,0])+B*max([Y-i,0]))

print(min(price))