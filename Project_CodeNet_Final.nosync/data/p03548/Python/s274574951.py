x, y, z = map(int, input().split())
if (x - 2 * z) % (y + z) >= y:
  result = (x - 2 * z) // (y + z) + 1
else:
  result = (x - 2 * z) // (y + z)
print(result)
