N=int(input())
A=[]
for i in range(N):
  A.append(int(input()))

A_sorted = sorted(A,reverse=True)

if N%2:
  a1=2*(sum(A_sorted[:N//2])-sum(A_sorted[N//2:]))+A_sorted[N//2]+A_sorted[N//2+1]
  a2=2*(sum(A_sorted[:N//2+1])-sum(A_sorted[N//2+1:]))-A_sorted[N//2]-A_sorted[N//2-1]
  print(max(a1,a2))
else:
  print(2*(sum(A_sorted[:N//2])-sum(A_sorted[N//2:]))-A_sorted[N//2-1]+A_sorted[N//2])