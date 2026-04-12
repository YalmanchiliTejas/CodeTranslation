N=int(input())
A=input().split()
A=[int(i) for i in A]
S=0
A_sum=0
for i in range(N):
    A_sum+=A[i]
    

B=A_sum
for i in range(N):
    B-=A[i]
    S+=A[i]*B

print(S%(pow(10,9)+7))