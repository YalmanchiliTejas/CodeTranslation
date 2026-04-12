import itertools
S=input()
SS=int(S)
N=len(S)
K=int(input())
def base9(n):
    res=""
    while(n>0):
        res=str((n%9)+1)+res
        n=n//9
    return "1"*(K-len(res))+res
ans=0
for seq in itertools.combinations(range(N),K):
    #print(seq,ans)
    low=0
    high=-1+9**K
    tmp=sum([9*10**(seq[i]) for i in range(K)])
    #print(tmp,SS)
    if tmp<=SS:
        ans+=9**K
        continue
    if tmp//9>SS:
        continue
    while(high-low>1):
        mid=(high+low)//2
        tmp2=base9(mid)
        tmp=sum([int(tmp2[i])*10**(seq[-i-1]) for i in range(K)])
        #print(tmp,tmp2,SS,low,mid,high)
        if tmp<=SS:
            low=mid
        else:
            high=mid
    ans+=low+1
print(ans)