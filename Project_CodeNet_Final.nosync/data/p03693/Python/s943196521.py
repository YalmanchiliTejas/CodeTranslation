try:
  r, g, b = map(int, input().split())
  print('YES' if (r*100+10*g+b) % 4 == 0 else 'NO')
except EOFError:
  pass