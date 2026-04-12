n=int(input())
c = list(map(int, input().rstrip().split()))
ans=0
b=10**9+7
sum1=0
for i in range(n):
    ans=(ans+c[i]*sum1)%b
    sum1=(sum1+c[i])%b

    
    
    
        
print(ans)