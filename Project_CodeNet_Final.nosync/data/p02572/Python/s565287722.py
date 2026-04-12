mod = pow(10, 9)+7
n = int(input())
lt = [int(x) for x in input().split()]

s = sum(lt)
ans = 0
for a in lt:
  s = s - a
  ans+= (a*s)%mod 
print(ans%mod)