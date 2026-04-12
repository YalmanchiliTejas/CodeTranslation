while True:
  n = int(input())
  if n==0:
    break
  else:
    l = [[0 for i in range(n)] for j in range(n)]
    x = n//2
    y = n//2+1
    c = 0
    while c < n**2:
      c += 1
      while l[y][x] != 0:
        y += 1
        if y >= n:
          y = 0
        x -= 1
        if x <= -1:
          x = n-1
      l[y][x] = c
      x += 1
      if x >= n:
        x = 0
      y += 1
      if y >= n:
        y = 0
    for i in l:
      a = ''
      for j in i:
        if 0 <= j < 10**1:
          a = a + '   ' + str(j)
        elif 10**1<=j<10**2:
          a = a + '  ' + str(j)
        elif 10**2<=j<10**3:
          a = a + ' ' + str(j)
      print(a)