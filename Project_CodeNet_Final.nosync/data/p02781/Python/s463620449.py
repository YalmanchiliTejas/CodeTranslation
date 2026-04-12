def nCk(n, k):
  return factorial(n)/factorial(n-k)/factorial(k)

from math import factorial
N = input()
K = int(input())
order = len(N)
diff = order - K 
if order < K:
  print(0)
else:
  s = int(N[0])
  #lower  = factorial(order-1)/factorial(diff-1)/ factorial(K) * (9**K)
  if order - 1 >= K:
    lower = nCk(order - 1, K) * (9**K)
  else:
    lower = 0
  total = lower
  for i in range(1, s):
  #  total += factorial(order-1)/factorial(diff)/ factorial(K-1) * (9**(K-1))
    total += nCk(order - 1, K - 1) * (9**(K-1))

  if K == 1:
    total += 1
  elif K == 2:
    under = int(N[1:])
    num = "0"*(order -1)
    for k in range(order - 1):
      for kk in range(1, 10):
        tmp = num[:k] + str(kk) + num[k+1:]
        if int(tmp) <= under:
          total += 1
  elif K == 3:
    under = int(N[1:])
    num = "0"*(order -1)
    for k in range(1, order - 1):
      for j in range(k):
        for kk in range(1, 10):
          for jj in range(1, 10):
            tmp = num[:j] + str(jj) + num[j+1:k] +str(kk) +  num[k+1:]
            if int(tmp) <= under:
              total += 1


  print(int(total))
  #pattern = factorial(order)/factorial(diff)/ factorial(K) * (9**K)