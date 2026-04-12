r, g, b = input().split()
a = int(r + g + b)
print(["NO", "YES"][a % 4 == 0])