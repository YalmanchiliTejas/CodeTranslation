n, x = map(int, input().split())
L = [1] * n
P_num = [1] * n

for i in range(n-1):
  L[i + 1] = L[i] * 2 + 3
  P_num[i + 1] = P_num[i] * 2 + 1

def pati_num(n, x):
  if n == 0:
    if x >= 1:
      return 1
    else:
      return 0
  elif x <= 1 + L[n-1]:
    return pati_num(n-1, x-1)
  else:
    return P_num[n-1] + 1 + pati_num(n-1, x-2-L[n-1])
print(pati_num(n, x))
