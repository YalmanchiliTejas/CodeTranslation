N=int(input())
s=list(map(int,input().split()))

ans=0
for a in range(1,N):
    Sf=0
    Sb=0
    used=[False]*((N-1)//a+1)
    for j in range((N-2)//a):
        Sf+=s[a*j]
        Sb+=s[N-1-a*j]
        if used[j]:
            break
        else:
            used[j]=True
        if (N-1-a*j)%a==0:
            if used[(N-1-a*j)//a]:
                break
            else:
                used[(N-1-a*j)//a]=True
        temp=Sf+Sb
        ans=max(ans,temp)

print(ans)
