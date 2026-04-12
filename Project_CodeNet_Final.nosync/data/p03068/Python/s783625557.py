import sys
input=sys.stdin.readline
 
N=int(input())
S=input()[:-1]
K=int(input())-1
for s in S:
  if s != S[K]:
    print("*",end='')
  else:
    print(s,end='')
print()