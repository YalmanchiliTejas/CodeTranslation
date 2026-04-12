while True:
  n = int(input())
  if n == 0:
    break
  score =[]
  for i in range(n):
    score.append(int(input()))
  print((sum(score)-min(score)-max(score))//(n-2))
