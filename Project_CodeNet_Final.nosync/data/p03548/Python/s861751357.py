x,y,z = input().split()
x = int(x)
y = int(y)
z = int(z)
x -= z
y += z
current = 0
c = 0

while current <= x:
    current += y
    c += 1

print(c-1)