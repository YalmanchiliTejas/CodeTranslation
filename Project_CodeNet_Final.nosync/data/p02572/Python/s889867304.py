N = int(input())
A = list(map(int,input().split()))
a = sum(A)
sum=0

for i in range(N):
    a-=A[i]
    sum= sum + A[i]*a

      

print(sum%1000000007)