a, b, c, x, y = map(int, input().split())
xy = [x, y]

total_ab = a * x + b * y
total_c = c * 2 * max(xy)
if x > y:
    total_abc = c * 2 * min(xy) + a * (x-y)
else:
    total_abc = c * 2 * min(xy) + b * (y-x)

total = [total_ab, total_c, total_abc]
print(min(total))