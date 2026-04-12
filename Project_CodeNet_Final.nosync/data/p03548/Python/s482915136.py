X, Y, Z = map(int, input().split())
person = 0

while (Y + Z) * (person + 1) + Z <= X:
    person += 1

print(person)
