N = int(input())
A = list(map(int, input().split()))
S=0
list = [0]*N
list[N-1]=A[N-1]%1000000007
for i in range(N-2,0,-1):
    list[i]=list[i+1]+A[i]%1000000007
    list[i]=list[i]%1000000007
for i in range(N-1):
    S=S+A[i]*list[i+1]%1000000007   
print(S%(1000000007))