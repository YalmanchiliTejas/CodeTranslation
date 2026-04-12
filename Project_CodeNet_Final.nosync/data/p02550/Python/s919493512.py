N,X,M=map(int, input().split())

ans=0
count=0
now=X
done=[-1]*(M-1)
L=[]
if now==0:
    print(ans)
    exit()
j=False
while True:
    if count==N:
        break

    if now==0:
        print(ans)
        exit()
    else:
        if done[now-1]==-1:
            done[now-1]=1
            L.append(now)
        else:
            for i in range(len(L)):
                if L[i]==now:
                    j=i
            break
    ans+=now
    count+=1
    now=(now**2)%M

if j:
    L=L[j:]

total=sum(L)
length=len(L)

ans+=((N-count)//length)*total
ans+=sum(L[:(N-count)%length])
print(ans)