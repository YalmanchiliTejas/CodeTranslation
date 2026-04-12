n, *lst = map(int, open(0).read().split())
a, b = sorted(lst)[n // 2 - 1:n // 2 + 1]
if a == b:
  print(*[a for _ in range(n)], sep='\n')
else:
  print(*[b if i <= a else a for i in lst], sep='\n')