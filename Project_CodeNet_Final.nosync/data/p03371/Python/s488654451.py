def resolve():
  a, b, c, x, y = map(int, input().split())
  ans = a * x + b * y
  ans = min(ans, max(x, y) * c * 2)
  if x >= y:
    ans = min(ans, y * c * 2 + (x - y) * a)
  else:
    ans = min(ans, x * c * 2 + (y - x) * b)

  print(ans)
  return

if __name__ == "__main__":
  resolve()
