def resolve():
  a, b, c, x, y = map(int, input().split())
  ans = a * x + b * y
  # A を AB で代替する
  ans = min(ans, c * x * 2 + max(0, b * (y - x)))
  # B を AB で代替する
  ans = min(ans, c * y * 2 + max(0, a * (x - y)))

  print(ans)
  return

if __name__ == "__main__":
  resolve()
