N=int(input())
L=list(map(int,input().split()))
M=0
for i in range(N) :
  if L[i] >= max(L[0:i+1]) :
    M+=1
print(M)