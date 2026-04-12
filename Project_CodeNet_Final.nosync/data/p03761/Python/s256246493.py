n=int(input())
s=[0]*n
for i in range(n):
  s[i]=list(input())
a=s[0]
a=sorted(list(set(a)))
b=[]
for j in range(len(a)):
  x=float("inf")
  for k in range(n):
    x=min(x,s[k].count(a[j]))
  for l in range(x):
    b.append(a[j])
print("".join(b))