a, b, c, x, y= map(int, input().split())

ans = a*x + b*y

if x > y:
    ans = min(ans, c * x * 2, y * c * 2+ (x - y) * a)
else:
    ans = min(ans, c * y * 2, x * c * 2 + (y - x) * b)
    
print(ans)