N,X,M=map(int,input().split())
t=[]
t.append(X)
temp=X
ans=X
for i in range(10**5+100):
    temp=temp**2%M
    if temp in t:
        firstindex=t.index(temp)
        currentindex=len(t)
        firstsum=0
        for i in range(firstindex):
            firstsum+=t[i]
        repeatsum=0
        for i in range(firstindex,currentindex):
            repeatsum+=t[i]
        repetition=(N-firstindex)//(currentindex-firstindex)
        lastrep=        (N-firstindex)%(currentindex-firstindex)
        lastsum=0
        for i in range(firstindex,firstindex+lastrep):
            lastsum+=t[i]
        print(firstsum+repetition*repeatsum+lastsum)
        exit()

    else:
        t.append(temp)

