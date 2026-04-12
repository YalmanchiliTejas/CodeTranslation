n=int(input())
s=input()
x=s[int(input())-1]
for i in range(n):
  if s[i]!=x:
    print("*",end="")
  else:
    print(x,end="")