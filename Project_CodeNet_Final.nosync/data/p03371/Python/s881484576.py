a,b,c,x,y = map(int, input().split())

base = a * x + b * y

if x < y:
    t = y
else:
    t = x
    
for i in range(t+1):
    money = a * max(0, x - i) + b * max(0, y - i) + 2 * c * i 
    if money < base:
        base = money

print(base)