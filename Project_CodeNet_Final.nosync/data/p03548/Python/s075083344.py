X, Y, Z = map(int, input().split())
count = 0
distance = 0
while distance <= X-Y-2*Z:
    distance += Y+Z
    count += 1
print(count)