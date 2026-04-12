a, b, c, x, y = map(int,input().split())
ans = a * x + b * y
z = 0
while x != 0 or y != 0:
    if x > 0:
        x -= 1
    if y > 0:
        y -= 1 
    z += 2
    ans = min(ans, a * x + b * y + c * z)
print(ans)