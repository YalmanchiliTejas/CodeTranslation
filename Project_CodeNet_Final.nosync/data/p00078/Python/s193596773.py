def square(n):
  mp = [[0 for _ in range(n)] for _ in range(n)]
  
  x, y = n // 2 , n // 2 + 1
  mp[y][x] = 1
  
  for i in range(2, n ** 2 + 1):
    x = (x + 1) % n
    y = (y + 1) % n
    
    while mp[y][x]:
      y = (y + 1) % n
      x = (x - 1) % n
    
    mp[y][x] = i
  
  for line in mp:
    s = ""    
    for i in line:
      si = str(i)
      s += si.rjust(4)
    print(s)

while True:
  n = int(input())
  if not n:
    break
  square(n)
