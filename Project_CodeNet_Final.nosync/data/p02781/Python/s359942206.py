N = input()
K = int(input())
def Anger(n, k):
  d = int(n[0])
  if len(n) < k:
    return 0
  else:
    if k == 1:
      if d == 0 and len(n) != 1:
        return Anger(n[1:], k)
      elif d == 0 and len(n) == 1:
        return 0
      else:
        if len(n) != 1:
          S = d + 9 * (len(n) - 1)
          return S
        else:
          return d
    else:
      if d == 0:
        return Anger(n[1:], k)
      else:
        S = (d - 1) * (9 ** (k-1))
        for j in range(k-1):
          S *= len(n) - j - 1
          S //= j + 1
        T = 9 ** k
        for j in range(k):
          T *= len(n) - j - 1
          T //= j + 1
        return S + T + Anger(n[1:], k - 1)
    
print(Anger(N, K))