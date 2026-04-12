N=int(input())
A=list(map(int,input().split()))
M=0
X=(10**9)+7
Y=0
for k in range (0,N):
  M=M + A[k]
  Y=A[k]*A[k]+Y
M =M*M
Z= (M-Y)//2
print(Z%X)