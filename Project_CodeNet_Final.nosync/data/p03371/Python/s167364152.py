a,b,c,x,y = map(int,input().split())
min_pizza = a*x + b*y
for i in range(1,max(x,y)+1):
  pizza = 2*c*i +max(0,x-i)*a + max(0,y-i)*b
  if pizza < min_pizza:
    min_pizza = pizza
print(min_pizza)