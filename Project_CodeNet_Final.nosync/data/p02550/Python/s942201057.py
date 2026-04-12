n,x,m = map(int,input().split())

a = x
r = [True for _ in range(m)]
s = []
while(r[a]):
  r[a] = False
  s.append(a)
  a = pow(a,2,m)
ai = s.index(a)
c = (n-len(s))//(len(s)-ai)
d = (n-len(s))-(len(s)-ai)*c
# print(i,ai,c,d)
ans = sum(s)+sum(s[ai:])*c+sum(s[ai:ai+d])
print(ans)