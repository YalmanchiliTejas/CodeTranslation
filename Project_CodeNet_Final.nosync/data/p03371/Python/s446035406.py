a, b, c, x, y = map(int, input().split())
l = []
kari = [x, y]
kari = max(kari)*2

for i in range(kari+1):
    if i%2!=0:
        continue

    a_p = a*(x-(i//2))
    b_p = b*(y-(i//2))
    if (i//2)>=x:
        a_p = 0
    if (i//2)>=y:
        b_p = 0
        
    price = (c*i)+ a_p + b_p
    l.append(price)


print(min(l))