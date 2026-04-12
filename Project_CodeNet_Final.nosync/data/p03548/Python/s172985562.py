X, Y, Z = map(int, input().split())
X -= Z
people = 0
while X >= 0:
    X -= (Y + Z)
    if X >= 0:
        people += 1
print(people)
