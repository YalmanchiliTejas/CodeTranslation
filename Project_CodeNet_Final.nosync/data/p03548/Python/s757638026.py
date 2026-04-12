X, Y, Z = map(int, input().split())
i = 0
width = Z
while True :
    width += Y + Z
    i += 1
    if X < width:
        break
print(i - 1)
