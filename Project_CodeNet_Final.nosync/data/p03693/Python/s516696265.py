r, g, b = [int(x) for x in input().split(" ")]

if (100 * r + 10 * g + b) % 4 == 0:
    print("YES")
else:
    print("NO") 