import re

N=int(input())
S=input()
K=int(input())
regex="[^"+S[K-1]+"]"
ans=re.sub(regex,"*",S)
print(ans)
