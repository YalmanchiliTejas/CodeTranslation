while 1:
  n=int(input())
  if not n:break
  l=[int(input()) for _ in range(n)]
  l.pop(l.index(max(l)))
  l.pop(l.index(min(l)))
  print(int(sum(l)/len(l)))
