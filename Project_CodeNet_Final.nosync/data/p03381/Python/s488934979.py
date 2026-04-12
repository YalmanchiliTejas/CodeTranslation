n=int(input())
x=list(map(int,input().split()))
s_x=sorted(x)
l,h=s_x[int(n/2-1)],s_x[int(n/2)]
for i in range(n):
  if x[i]<=l:
    print(h)
  else:
    print(l)