n = int(input())
list = [input() for _ in range(n)]
alpha = [chr(i) for i in range(ord('a'), ord('z')+1)]
for a in alpha:
  print(a*(min([i.count(a) for i in list])),end="")