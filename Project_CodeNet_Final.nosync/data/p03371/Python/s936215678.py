a,b,c,x,y = list(map(int, input().split()))
m = 0
cheap = min(a+b, c*2)
if x >= y:
    m += y*cheap
    x -= y
    cheap = min(a, c*2)
    m += x*cheap
else:
    m += x*cheap
    y -= x
    cheap = min(b, c*2)
    m += y*cheap
print(m)