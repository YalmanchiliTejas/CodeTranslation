n=int(input())
C=[chr(i) for i in range(97,123)]
L=[50]*26
for i in range(n):
  a=input()
  for j in range(26):
    L[j]=min(L[j],list(a).count(C[j]))
for i in range(26):
  print(C[i]*L[i],end="")
print("\n",end="")