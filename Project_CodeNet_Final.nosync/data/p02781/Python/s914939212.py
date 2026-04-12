def comb(n,k):
  if n == 0:
    return 0
  if n == k:
    return 1
  
  num = 1
  for i in range(n-k+1,n+1):
    num *= i
    
  for i in range(2,k+1):
    num //= i
    

  return num
    
def syou(n,k):
  if k == 0:
    return 1
  
  if len(n) < k:
    return 0
  
  if len(n) == 1:
    return int(n)
  
  l = len(n)
  if n[0] == '0':
    return syou(n[1:l], k)
  
  ans = comb(l-1, k) * (9**k)
  
  top = int(n[0])
  ans += comb(l-1, k-1) * (top-1) * (9**(k-1))
  
  ans += syou(n[1:l], k-1)
  return ans


n = input()
k = int(input())

print(syou(n, k))