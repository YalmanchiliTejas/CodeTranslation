N,T,E=map(int,input().split())
x=list(map(int,input().split()))
a=[i for i in range(T-E,T+E+1)]
ans=-1
for i in range(N):
    for j in range(len(a)):
        if a[j]%x[i]==0:
            ans=(i+1)
            break
        else:
            pass
    if ans==-1:
        pass
    else:
        break
print(ans)
