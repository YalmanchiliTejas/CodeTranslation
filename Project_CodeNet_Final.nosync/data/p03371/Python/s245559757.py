a, b, c, x, y = map(int, input().split())
m = 0
z = min(x, y)
m += 2 * z * c if 2 * z * c <= (a * z + b * z)else (a * z + b * z) 
w = max(x, y) - min(x, y)
d = a if x > y else b
m += 2 * w * c if 2 * w * c <= d * w else d * w
print(m)