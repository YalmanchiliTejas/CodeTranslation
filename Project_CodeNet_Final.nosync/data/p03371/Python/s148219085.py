a,b,c,x,y = map(int, input().split())
only = a * x + b * y 
ans = only
for i in range(1,x + 1):
    current = 0
    current = c * i * 2
    if y - i >= 0:
        current = current + a * ( x - i ) + b * (y - i)
    else:
        current = current + a * ( x - i )
    if ans > current:
        ans = current
for i in range(1,y + 1):
    current = 0
    current = c * i * 2
    if x - i >= 0:
        current = current + a * ( x - i ) + b * ( y - i )
    else:
        current = current + b * ( y - i )
    if ans > current:
        ans = current
print(ans)