a, b, c, x, y = map(int, input().split())

ab = max(x, y) * 2 * c
a_b = a * x + b * y
if x >= y:
    ab_a_b = y*2*c + (x-y)*a
else:
    ab_a_b = x*2*c + (y-x)*b

print(min(ab, a_b, ab_a_b))