import math

def Comb(n, r):
  if n < r:
    return 0
  else:
    return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))

N = input()
K = int(input())
ans = 0
for i in range(1, len(N)):
  if i < K:
    pass
  else:
    ans += 9 ** K * Comb(i-1, K-1)
ans += (int(N[0])-1) * Comb(len(N)-1, K-1) * 9 ** (K-1)
if K == 1:
  ans += 1
elif K == 2:
  for i in range(1, len(N)):
    if N[i] != '0':
      ans += int(N[i]) + 9 * (len(N) - i - 1)
      break
else:
  for i in range(1, len(N)):
    if N[i] != '0':
      if len(N) - i - 1 >= 2:
        ans += Comb(len(N) - i - 1, 2) * 9 ** 2
      if len(N) - i - 1 >= 1:
        ans += (int(N[i]) - 1) * 9 * (len(N) - i - 1)
      for j in range(i+1, len(N)):
        if N[j] != '0':
          ans += int(N[j]) + 9 * (len(N) - j - 1)
          break
      break
print(ans)
