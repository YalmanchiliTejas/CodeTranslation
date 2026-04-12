n,x,m = map(int,input().split())

a = x
r = [False for _ in range(m)]
s = []
i = 0
while(r[a] == False and i < n):
  r[a] = True
  s.append(a)
  a = pow(a,2,m)
  i += 1
if i == n:
  ans = sum(s)
else:
  ai = s.index(a)
  c = (n-len(s))//(len(s)-ai)
  d = (n-len(s))-(len(s)-ai)*c
  # print(i,ai,c,d)
  ans = sum(s)+sum(s[ai:])*c+sum(s[ai:ai+d])
print(ans)