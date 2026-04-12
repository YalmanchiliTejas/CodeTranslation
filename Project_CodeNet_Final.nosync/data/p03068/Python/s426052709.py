n=int(input())
s=input()
k=int(input())
tar=s[k-1]
for c in s:
  if c!=tar: print("*",end="")
  else: print(c,end="")