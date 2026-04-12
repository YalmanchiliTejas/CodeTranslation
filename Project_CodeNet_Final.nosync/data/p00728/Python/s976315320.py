while True:
  n = int(input())
  if n ==0:
    break
  else:
    list1=[0]*n
    for i in range(n):
      list1[i]=int(input())
    print( (sum(list1)-max(list1)-min(list1))//(len(list1)-2) )
