N=int(input())
S=[input() for i in range(N)]
X=[50]*26
for i in range(N):
  Y=[0]*26
  for j in range(len(S[i])):
    Y[ord(S[i][j])-ord('a')]+=1
  for j in range(26):
    X[j]=min(X[j],Y[j])
for i in range(26):
  for j in range(X[i]):
    print(chr(i+ord('a')),end="")
print()