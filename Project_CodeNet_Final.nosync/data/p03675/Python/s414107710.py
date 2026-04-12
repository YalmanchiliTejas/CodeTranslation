n = int(input())
alst = input().split()
lst1 = alst[::2]
lst2 = alst[1::2]
if n % 2:
  lst1.reverse()
  print(' '.join(lst1 + lst2))
else:
  lst2.reverse()
  print(' '.join(lst2 + lst1))
