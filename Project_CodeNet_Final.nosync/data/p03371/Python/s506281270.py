a,b,c,x,y=map(int,input().split())
li=[]

for i in range(10**5+1):
  price=2*c*i+a*max(0,x-i)+b*max(0,y-i)
  li.append(price)
  
print(min(li))