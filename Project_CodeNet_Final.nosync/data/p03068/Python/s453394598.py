N=int(input())
S=input()
K=int(input())

for i in range(N):
  if S[K-1] == S[i]:
    print(S[i],end="")
  else:
    print("*",end="")
    
print("\n")
