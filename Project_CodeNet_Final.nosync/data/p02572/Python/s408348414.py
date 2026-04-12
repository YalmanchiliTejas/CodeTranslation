def multmod(a,b,m):
  ans = 0
  a = a % m
  
  while b:
    if (b & 1): # odd
      ans = (ans + a) % m
    
    a = (2 * a) % m
    b >>= 1 # b = b / 2
    
  return ans

n = int(input())
S = [int(a) for a in input().split()]
divisor = 10**9 + 7
tot = 0
a,b = 0,0
arr_sum = sum(S) #% divisor
arr_ssq = arr_sum*arr_sum #% divisor
isq_sum = 0
for i in range(n):
  isq_sum += S[i]*S[i] #% divisor
  
#isq_sum = isq_sum % divisor
tot = (arr_ssq - isq_sum)//2 % divisor

print(tot)