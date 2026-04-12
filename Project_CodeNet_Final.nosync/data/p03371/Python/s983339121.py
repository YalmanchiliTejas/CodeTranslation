a, b, c, x, y = list(map(int, input().split()))
#b = list(map(int, input().split()))
x2 = x
y2 = y
total = 0
m = x
if a+b > c*2:
    total += m*c*2
    x -= m
    y -= m

if x > 0:
    total += x*a
if y > 0:
    total += y*b



total2 = 0
m = y2
if a+b > c*2:
    total2 += m*c*2
    x2 -= m
    y2 -= m

if x2 > 0:
    total2 += x2*a
if y2 > 0:
    total2 += y2*b


print(min(total,total2))    