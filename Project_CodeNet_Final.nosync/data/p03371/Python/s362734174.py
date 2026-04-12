a,b,c,x,y = map(int,input().split())
s = 0
k = 2 * c
money = 0
s = min(a+b,k)
if k<a:
    a = k
if k<b:
    b = k
little = min(x,y)
money = little * s
x -= little
y -= little
if x:
    money += x*a
elif y:
    money += y*b
print(money)
