x, y, z = map(int, input().split())

# width = x cm, ycm の幅を取りつつ、間隔Zcmあけて座る
add_s = x % (y + z)  # additional_space
if add_s < z:
  print(x // (y+z) - 1)
else:
  print(x // (y+z))