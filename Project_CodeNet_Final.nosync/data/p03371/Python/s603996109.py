cols = input('').split()

a = int(cols[0])
b = int(cols[1])
c = int(cols[2])
x = int(cols[3])
y = int(cols[4])

total_ab = x * a + b * y

if x >= y:
    total_ac = c * y * 2 + (x - y) * a
    total_bc = c * x * 2
else:
    total_ac = c * y * 2
    total_bc = c * x * 2 + (y - x) * b

print(min(total_ab, total_ac, total_bc))