N=int(input())
S=input()
K=int(input())

p=S[K-1]
ans=""
for i in S:
    if i==p:
        ans+=i
    else:
        ans+="*"
        
print(ans)