n,x,m=map(int,input().split())
tab=[0 for i in range(10**5+1)]

end=False
now=x
for i in range(1,n+1):
    if tab[now]>0:
        las=tab[now]
        cyc=i-las
        break
    tab[now]=i
    now=now*now%m
else:
    end=True
    
if end:
    ans=0
    for i in range(10**5+1):
        if tab[i]>0:
            ans+=i
    print(ans)
else:
    ans=0
    head=0
    body=0
    foot=0
    lop=(n-las)//cyc
    rem=(n-las)%cyc
    for i in range(10**5+1):
        if tab[i]>=las and las+rem>=tab[i]:
            body+=i
            foot+=i
        elif tab[i]>=las:
            body+=i
        elif tab[i]>0:
            head+=i
    ans=head+body*lop+foot
    print(ans)
        
    
    