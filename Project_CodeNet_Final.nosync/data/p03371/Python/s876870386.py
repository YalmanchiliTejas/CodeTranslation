# coding:utf-8

a,b,c,x,y = map(int, input().split())
price = [] 

for i in range(1000000):
    p = 2 * c * i
    if i < x:
        p += a * (x - int(i))
    if i < y:
        p += b * (y - int(i))
    
    price.append(p)

print(min(price))
    

"""
if (a>c):
    p += c*x*2
    flag = 1

else:
    p += a*x
    flag = 0

if (b>c) :
    if (flag==1):
        p+= (y-int(x/2)) * c
    else:
        p+= c*y*2
else:
    if (flag==1):
        p+= (y-int(x/2)) * c
    else:
        p+= b*y

print(p)

"""



