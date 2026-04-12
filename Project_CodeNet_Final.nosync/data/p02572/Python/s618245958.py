import sys
input = sys.stdin.readline

n=int(input())

A=list(map(int,input().split()))

B=[A[0]]

for i in range(len(A)-1):
    B.append((B[i]+A[i+1]) % (10**9+7))

ans=0

for i in range(n-1):
    
    ans += (A[i] * (B[-1]-B[i])  % (10**9+7))
    
#    for j in range(i+1,n):
        
#        ans += (A[i] * A[j]) % (10**9+7)
#
print(ans % (10**9+7))