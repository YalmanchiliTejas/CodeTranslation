a,b,c,x,y = map(int,input().split())

k = 0 #価格
if c*2 < a+b:
    z = min([x,y])
    k += z*c*2
    x -= z
    y -= z

if c*2 < a: k += x*c*2
else: k += x*a
    
if c*2 < b: k += y*c*2
else: k += y*b

print(k)