N=input()
keta=len(N)
K=int(input())
seiyaku=[[0 for a in range(120)] for b in range(keta+2)]
museiyaku=[[0 for a in range(120)] for b in range(keta+2)]
seiyaku[0][0]=1
seiyaku[0][0]=1
for i in range(keta):
 a=int(N[i])
 for j in range(keta+1):
  if a==0:
   seiyaku[i+1][j]=seiyaku[i][j]
   museiyaku[i+1][j+1]+=museiyaku[i][j]*9
   museiyaku[i+1][j]+=museiyaku[i][j]
  else:
   seiyaku[i+1][j+1]=seiyaku[i][j]
   museiyaku[i+1][j]+=seiyaku[i][j]
   museiyaku[i+1][j+1]+=seiyaku[i][j]*(a-1)
   museiyaku[i+1][j+1]+=museiyaku[i][j]*9
   museiyaku[i+1][j]+=museiyaku[i][j]
print(seiyaku[keta][K]+museiyaku[keta][K])