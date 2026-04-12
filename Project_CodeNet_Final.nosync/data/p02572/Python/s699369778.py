N = int(input())
A = list(map(int, input().split()))
 
s = 0
for i in range(N):
  s += A[i]
  s %= (10**9+7)
s = s**2
s %= (10**9+7)
 
t = 0
for i in range(N):
  t += (A[i]**2 % (10**9+7))
t %= (10**9+7)
 
ans = (s-t) % (10**9+7)
'''
tmp = (2**1000000005) % (10**9+7)
'''
tmp = 500000004
ans *= tmp
ans %= (10**9+7)
print(ans)