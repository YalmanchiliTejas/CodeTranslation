n = int(input())
lst = list(map(int, input().split()))

MOD = 1000000007

def mod(n):         
  return n % MOD

def multiply(a, b): #mod(a*b)を求める
  return mod(mod(a)*mod(b))

ans = sum(lst)**2

for i in range(n):
  ans -= lst[i]**2
  
ans = ans//2
print(mod(ans))