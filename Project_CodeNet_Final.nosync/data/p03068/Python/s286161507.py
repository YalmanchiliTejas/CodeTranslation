n=int(input())
a=list(input())
k=int(input())

s=a[k-1]

for i in range(n):
  if a[i] != s:
    a[i] = "*"
 
print("".join(a))