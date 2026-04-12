n = int(input())
l=input()
m=l[int(input())-1]
k=""
for i in range(n):
  if l[i]!=m:
    k+="*"
  else:
    k+=l[i]
print(k)