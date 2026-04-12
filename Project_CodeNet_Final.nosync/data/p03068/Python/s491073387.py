n=int(input())
s=list(input())
k=int(input())
tmp=s[k-1]
for i in range(n):
  print(s[i],end="") if s[i]==tmp else print("*",end="")
print("")