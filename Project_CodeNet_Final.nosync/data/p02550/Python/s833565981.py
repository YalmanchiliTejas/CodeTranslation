n,x,m=map(int,input().split())
ans=0
if n<=10**6:
    for i in range(n):
        ans+=x%m
        x*=x
        x%=m
    print(ans)
else:
    lis=[x]
    s={x}
    while 1:
        x*=x
        x%=m
        if x in s:
            num=x
            break
        lis.append(x)
        s.add(x)
    for i in range(len(lis)):
        if lis[i]==num:
            idx=i
    cnt=(n-idx)//(len(lis)-idx)
    idx2=(n-idx)%(len(lis)-idx)
    #print(lis)
    suma=0
    sumb=0
    for i in range(len(lis)):
        if i<idx:
            suma+=lis[i]
        else:
            sumb+=lis[i]
    ans+=suma+sumb*cnt
    for i in range(idx2):
        ans+=lis[idx+i]
    print(ans)