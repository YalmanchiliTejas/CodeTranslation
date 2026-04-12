n, x = map(int, input().split())

def num_patty(n, x):
  if 2**(n+2)-3 <= x:
    return 2**(n+1)-1
  elif 2**(n+1) <= x and x <= 2**(n+2)-4:
    return num_patty(n-1, x-2**(n+1)+1)+(2**n-1)+1
  elif x == 2**(n+1)-1:
    return (2**n-1)+1
  elif 2 <= x and x <= 2**(n+1):
    return num_patty(n-1, x-1)
  else:
    return 0
    
print(num_patty(n, x))