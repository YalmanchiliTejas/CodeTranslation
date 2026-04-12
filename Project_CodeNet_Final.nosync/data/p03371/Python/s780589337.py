a,b,c,x,y = map(int,input().split())

mid = min(x,y)
rest = max(x,y)-mid
if x>y: a_b = a
else: a_b = b

total = 0
# until mid
if 2*c <  a+b:
    total += mid*2 *c
else:
    total += mid   *(a+b)
    
#until end
if 2*c < a_b:
    total += rest*2 *c
else:
    total += rest   *a_b

print(total)