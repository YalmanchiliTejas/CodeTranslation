n=int(input())
s=input()
k=int(input())
a=s[k-1]
for i in range(n):
  if s[i]==a:
    print(a,end="")
  else:
    print("*",end="")