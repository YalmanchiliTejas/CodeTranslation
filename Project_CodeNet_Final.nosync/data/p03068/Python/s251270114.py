n=int(input())
s=input()
k=int(input())
a=s[k-1]
for _ in s:
  if _ == a:
    print(a,end="")
  else:
    print("*",end="")