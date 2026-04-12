while True:
  n=int(input())
  if n==0:
    break
  lists=[]
  for i in range(n):
    lists.append(int(input()))
  a=max(lists)
  b=min(lists)
  x=int(len(lists))
  average=(sum(lists)-a-b)/(x-2)
  print(int(average))
