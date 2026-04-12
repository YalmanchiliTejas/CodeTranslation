while True:
  n = int(input())
  if n == 0: break
  
  s=[int(input()) for i in range(n)]
  s.sort()
  point = (sum(s)-max(s)-min(s))//(len(s)-2)
  print(point)
