# coding: utf-8
# Your code here!
N=int(input())
s=list(input())
s=list(map(lambda x:0 if x=="o" else 1,s))

#print(s)

ans=[0]*N
ans[0]=1
ans[1]=1
#sheep=0 wolf=1

for _ in range(2):
    ans[0]^=1
    for __ in range(2):
        ans[1]^=1
        for i in range(2,N):
            ans[i]=-1
        for i in range(2,N):
            ans[i]=ans[i-1]^s[i-1]^ans[i-2]
        if s[0]^ans[0]==ans[1]^ans[-1] and s[-1]^ans[-1]==ans[0]^ans[-2]:
            #print(ans)
            ans=list(map(lambda x:"S" if x==0 else "W", ans))
            print("".join(ans))
            exit()

print(-1)