n, x = map(int, input().split())

def count_p(n, x):
  if x == 0:
    return 0
  elif n == 0:
    return 1
  elif x > 2**(n+1)-2:
    return 2**(n)-1 + 1 + count_p(n-1, min(x-(2**(n+1)-1), 2**(n+1)-3))
  else:
    return count_p(n-1, x-1)
  
print(count_p(n,x))
