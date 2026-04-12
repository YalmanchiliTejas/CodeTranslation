import sys
h,w=map(int,input().split())
f=[[] for i in range(h)]
for i in range(h):
  inv=input()
  for j in range(w):
    if inv[j]=="#":
      f[i].append(j)
c=0
for i in f:
  if c!=i[0]:
    print("Impossible");sys.exit()
  if i[-1]-i[0]>=len(i):print("Impossible");sys.exit()
  c=i[-1]
print("Possible")
