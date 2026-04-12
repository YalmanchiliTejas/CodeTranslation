n=int(input())
h=list(map(int,input().split()))	
M=h[0]
ans=1
for i in range(n-1):
    i+=1
    if M<h[i-1]:
        M=h[i-1]
    if M<=h[i]:
        ans+=1
print(ans)
    

