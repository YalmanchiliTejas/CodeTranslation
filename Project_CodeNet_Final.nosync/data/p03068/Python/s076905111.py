N,S,K=int(input()),input(),int(input())
s=S[K-1]

for i in list("abcdefghijklmnopqrstuvwxyz"):
  if i!=s:
    S=S.replace(i,"*")
print(S)