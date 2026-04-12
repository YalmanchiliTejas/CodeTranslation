N=int(input())
S=list(input())
K=int(input())
w=S[K-1]
ans=""
for i in range(N):
    if S[i]==w:
        ans+=w
    else:
        ans+="*"
print(ans)