n,p,m = list(map(int,input().split()))

seen = {}
ans = p%m
seen[p%m]=1
T = {}
T[1] = ans
T[0] = 0
last_p = p%m

r = 0

if n==1:
  print(p%m)
  exit()
else:
  for i in range(2,m+1000):
    p = p ** 2
    p = p % m
    
    if p not in seen:
      seen[p]=i
    else:
      r = i-seen[p]
      last_p = p
      break
    
    ans += p
    T[i] = ans
    
    if i==n:
      print(ans)
      exit()
    
    
temp = T[seen[p]-1]
ans -= temp
n -= seen[p]

k = n//r
ans *= k
ans += temp

n = n % r

if n==0:
  print(ans+last_p)
  exit()

for i in range(1,m+1000):
  p = p ** 2
  p = p % m
  ans += p
  if i==n:
    print(ans+last_p)
    exit()
      
      
    