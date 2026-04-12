def main():
  r, g, b = map(lambda i: int(i), input().split(' '))
  n = 100 * r + 10 * g + b
  print('YES' if n % 4 == 0 else 'NO')

main()