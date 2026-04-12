N=int(input())
s=input()
flag=False
def check(s,bef,now,nex):
    if s=='o':
        if now=='S':
            if bef==nex:return True
        elif now=='W':
            if bef!=nex:return True
    elif s=='x':
        if now=='S':
            if bef!=nex:return True
        elif now=='W':
            if bef==nex:return True
    return False

for x in ['SS','SW','WS','WW']:
    if flag==True:break
    ans=x
    bef,now=x[0],x[1]
    for i in range(2,N):
        if s[i-1]=='o':
            if bef==now:
                ans+='S'
                bef,now=now,'S'
            elif bef!=now:
                ans+='W'
                bef,now=now,'W'
        elif s[i-1]=='x':
            if bef!=now:
                ans+='S'
                bef,now=now,'S'
            elif bef==now:
                ans+='W'
                bef,now=now,'W'
    if check(s[N-1],ans[N-2],ans[N-1],ans[0])==True and check(s[0],ans[N-1],ans[0],ans[1])==True:
        flag=True
        break
if flag==False:print('-1')
else:print(ans)