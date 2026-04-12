a,b,c,x,y = map(int, input().split())
a = int(a)
b = int(b)
c = int(c)
x = int(x)
y = int(y)

z = min(x,y)
w = abs(x - y)
count = 0

if 2 * c > a + b:
    count += (a + b) * z
else:
    count += 2 * c * z

if x > y:
    if 2 * c < a:
        count += 2 * c * w
    else:
        count += a * w
elif x < y:
    if 2 * c < b:
        count += 2 * c * w
    else:
        count += b * w

print(count)