N,X,M=map(int,input().split())
dist=[0 for i in range(M)]
A=X
loopin=-1
loopout=-1
ans=[0]
for i in range(N+1):
    if dist[A]!=0:
        loopin=dist[A]
        loopout=i
        ans.append(ans[-1]+A)
        break
    else:
        dist[A]=i
        ans.append(ans[-1]+A)
        A=(A*A)%M
if loopin==-1:
    print(ans[N])
    exit()
#print(roopin,roopout)
#print(ans)
A=X
loop=loopout-loopin
def solve(l,r):
    assert 0<=l and l<=r
    if r<=loopout:
        return ans[r]-ans[l]
    if l<loopin:
        return ans[loopin]-ans[l]+solve(loopin,r)
    x=(l-loopin)//loop
    y=(r-loopin)//loop
    #x*loop+loopin<=l<(x+1)*loop+loopin
    #y*loop+loopin<=r<(y+1)*loop+loopin
    if x==y:
        return ans[r-y*loop]-ans[l-x*loop]
    #以降はx<y
    tmp1=ans[l-x*loop]-ans[loopin]
    tmp2=(ans[loopout]-ans[loopin])*(y-x)
    tmp3=ans[r-y*loop]-ans[loopin]
    #print(l,r,x,y,tmp1,tmp2,tmp3)
    return tmp1+tmp2+tmp3
print(solve(0,N))
