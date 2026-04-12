n, x = map(int, input().split())

l = [0]*(n+1)
l[0] = 1
for i in range(1,n+1):
  l[i] = l[i-1]*2+3

p = [0]*(n+1)
p[0] = 1
for i in range(1,n+1):
  p[i] = p[i-1]*2+1
  
ans = 0  
def bts(a,b):
  global ans
  if b == 1:
    ans += 0
  elif 1 < b < l[a-1]+1:
    bts(a-1,b-1)
  elif b == l[a-1]+1:
    ans += p[a-1]
  elif b == l[a-1]+2:
    ans += p[a-1]+1
  elif l[a-1]+2 < b < l[a-1]*2+2:
    ans += p[a-1]+1
    bts(a-1,b-2-l[a-1])
  else:
    ans += p[a]

bts(n,x)
  
print(ans)
