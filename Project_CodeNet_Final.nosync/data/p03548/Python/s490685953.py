data = list(map(int, input().split()))
x = data[0]
y = data[1]
z = data[2]
people = int((x - z) / (y + z))
print(people)
