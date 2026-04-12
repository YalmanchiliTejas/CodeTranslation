a, b, c, x, y = [int(i) for i in input().strip().split(" ")]

z = min(x, y)
total = 0

if (a+b) > c*2:
    total += c * 2 * z
else:
    total += a * z + b * z

if (a < c * 2):
    total += (x-z) * a
else:
    total += (x-z) * c * 2

if (b < c * 2):
    total += (y-z) * b
else:
    total += (y-z) * c * 2

print(total)
