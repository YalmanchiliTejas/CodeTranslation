def resolve():
  a, b, c, x, y = map(int, input().split())
  ans = a * x + b * y
  ans = min(ans, c * max(x, y) * 2)
  if x > y:
    ans = min(ans, 2 * c * y + a * (x - y))
  else:
    ans = min(ans, 2 * c * x + b * (y - x))

  print(ans)
  return

if __name__ == "__main__":
  resolve()
