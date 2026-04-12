N=int(input())
A=[int(x) for x in input().split()]

out=0
Max_H=0
for i in range(N):
  if Max_H <= A[i]:
    out+=1
    Max_H=A[i]
    
print(out)