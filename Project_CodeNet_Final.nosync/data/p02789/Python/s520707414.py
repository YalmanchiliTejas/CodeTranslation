def judge(n, m):
  if n == m:
    print('Yes')
  else:
    print('No')
    
a, b = map(int, input().split())
judge(a, b)