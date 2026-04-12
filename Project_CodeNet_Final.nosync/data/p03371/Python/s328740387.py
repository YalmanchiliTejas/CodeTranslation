a, b, c, x, y = map(int, input().split())
out1 = a * x + b * y
if x > y:
    out2 = x*c*2
    out3 = y*c*2 + (x-y)*a
else:
    out2 = y*c*2
    out3 = x*c*2 + (y-x)*b
print(min([out1, out2, out3]))