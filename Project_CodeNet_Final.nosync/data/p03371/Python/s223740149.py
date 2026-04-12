a, b, ab, x, y = map(int, input().split())
ave = (a + b) / 2
minxy = min(x, y)
amt = 0

if ave > ab:
    amt += ab * minxy * 2
else:
    amt += (a + b) * minxy
    
if x == minxy:
    if b / 2 > ab:
        amt += ab * (y - minxy) * 2
    else:
        amt += b * (y - minxy)
else:
    if a / 2 > ab:
        amt += ab * (x - minxy) * 2
    else:
        amt += a * (x - minxy)
        
print(amt)