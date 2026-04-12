r, g, b = map(int, input().split())

RGB = int(r*100 + g*10 + b)

if RGB % 4 == 0:
    print("YES")
else:
    print("NO")