n = int(input())
l = list(map(int,input().split()))
s = 0
s1 = sum(l)
a = 0
for x in range(n-1):
  s+=(l[x]*(s1-l[x]-a))
  a+=l[x]
print(s%1000000007)
