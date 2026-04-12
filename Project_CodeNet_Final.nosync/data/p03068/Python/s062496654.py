#B
N=int(input())
S=input()
K=int(input())
ans=""
for i in S:
    if S[K-1] !=i:
        ans+= "*"
    else:
        ans+=S[K-1]
print(ans)