x,y,z = map(int, input().split())
a = z
i = 0
while a < x:
    a += y+z
    i += 1
if a > x:
    i -= 1
print(i)