n=int(input())
h=[int(i) for i in input().split()]
s=0
hmax=h[0]
for k in range(n):
  if hmax <= h[k]:
    s =s+1
    hmax=h[k]
  else:
    continue
print(s)   
