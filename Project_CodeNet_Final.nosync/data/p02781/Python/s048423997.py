def nCr(n,r):
  ret = 1
  for i in range(r):
    ret *= n-i
    ret /= i+1
  return ret

def top(N,K):
  if K == 0:
    return 1
  L = len(N)
  ans = 0
  if L < K:
    return 0
  else:
    ans += nCr(L-1,K) * 9 ** K

    u = int(N[0])
    z = N.count('0')
    o = N.count('1')
    f = 0
    if z + o == L:
      f = 1
    if f == 0:
      ans += (u - 1) * nCr(L-1,K - 1) * 9 ** (K - 1)
      if L == 1:
        return ans + 1
      else:
        return ans + top(str(int(N[1:])),K - 1)
    else:
      if len(str(int(N[1:]))) != 1:
        return ans + top(str(int(N[1:])),K - 1)
      else:
        if o >= K:
          return ans + 1
        else:
          return ans

N = str(input())
K = int(input())

print(int(top(N,K)))