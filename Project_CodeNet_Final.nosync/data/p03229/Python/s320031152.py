n=int(input())
data=[int(input()) for i in range(n)]
data.sort()


ans=0
head=0
tail=n-1

tmp=n//2
for i in range(n-1):
    if(i%2==0):
        ans+=abs(data[tmp] - data[head])
        tmp=head
        head+=1
    else:
        ans+=abs(data[tmp] - data[tail])
        tmp=tail
        tail-=1

if(i%2==1):
    tmp_ans=ans
    ans=0
    head=0
    tail=n-1

    tmp=n//2
    for i in range(n-1):
        if(i%2==1):
            ans+=abs(data[tmp] - data[head])
            tmp=head
            head+=1
        else:
            ans+=abs(data[tmp] - data[tail])
            tmp=tail
            tail-=1
    ans=max([tmp_ans,ans])

print(ans)