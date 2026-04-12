N,X,M=map(int,input().split())
modlist=[0]*M
modset=set()
ans=0
for i in range(M):
    if X in modset:
        startloop=modlist.index(X)
        sum_outofloop=sum(modlist[:startloop])
        inloop=ans-sum_outofloop
        numofloop=(N-startloop)//(i-startloop)
        ans=sum_outofloop+numofloop*inloop+sum(modlist[startloop:startloop+((N-startloop)%(i-startloop))])
        #print(inloop,i,startloop,sum_outofloop,numofloop,sum(modlist[startloop:startloop+((N-startloop)%(i-startloop))]))
        break
    else:
        modset.add(X)
        ans+=X
        modlist[i]=X
        X**=2
        X%=M
    if i==N-1:
        break
print(ans)
#print(modlist)