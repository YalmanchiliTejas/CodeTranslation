[N,X] = list(map(int,input().split(' ')))

def paty(n,x):
  #print('n:{}'.format(n))
  #print('x:{}'.format(x))
  if x == 0:
    return 0
  if n == 0:
    return x
  elif ((2**(n+2))-3 - 1) / 2 >= x:
    return paty(n-1,x-1)
  elif ((2**(n+2))-3 + 1) / 2 == x:
    return 2**n
  elif ((2**(n+2))-3) - 1 <= x:
    return 2**(n+1) - 1
  else:
    return 2**n + paty(n-1, x-((2**(n+1))-3) -2)
  
ans = paty(N,X)
print(ans)