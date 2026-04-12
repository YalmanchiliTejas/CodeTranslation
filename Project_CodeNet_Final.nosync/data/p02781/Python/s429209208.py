def comb(n, k):
  if n < k:
    return 0
  else:
    res = 1
    _n = n
    for _k in range(1, k+1):
      res *= _n
      res //= _k
      _n -= 1
    
    return res
    

N = input()
n = len(N)
K = int(input())

ans = comb(n-1, K) * (9**K)

if K == 1:
  ans += int(N[0])
elif K == 2:
  ans += comb(n-1, 1) * 9 * (int(N[0])-1)
  N = str(int(N) - int(N[0])*(10**(n-1)))
  n = len(N)
  ans += comb(n-1, 1) * 9
  ans += int(N[0])
else: # K == 3
  ans += comb(n-1, 2) * (9**2) * (int(N[0])-1)
  N = str(int(N) - int(N[0])*(10**(n-1)))
  n = len(N)
  ans += comb(n-1, 2) * (9**2)
  ans += comb(n-1, 1) * 9 * (int(N[0])-1)
  N = str(int(N) - int(N[0])*(10**(n-1)))
  n = len(N)
  ans += comb(n-1, 1) * 9
  ans += int(N[0])

print(ans)