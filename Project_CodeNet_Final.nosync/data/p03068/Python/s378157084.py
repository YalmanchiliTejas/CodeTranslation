N = int(input())
S = str(input())
K = int(input())
H = ""
for i in range(N):
  if(S[i]==S[K-1]):
    H+=S[i]
  else:
    H+="*"
print(H)
