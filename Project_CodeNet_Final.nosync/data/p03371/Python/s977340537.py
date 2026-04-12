a, b, c, x, y = map(int, input().split())

cost = 0
a_count = 0
b_count = 0

while a_count < x and b_count < y:
    if a + b < 2 * c:
        cost += a + b
        a_count += 1
        b_count += 1
    else:
        cost += 2 * c
        a_count += 1
        b_count += 1

while a_count < x:
    if a < 2 * c:
        cost += a
        a_count += 1
    else:
        cost += 2 * c
        a_count += 1
        b_count += 1

while b_count < y:
    if b < 2 * c:
        cost += b
        b_count += 1
    else:
        cost += 2 * c
        a_count += 1
        b_count += 1

print(cost)