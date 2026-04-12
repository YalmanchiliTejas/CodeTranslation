N=int(input())
ans=[]
m=10**10
for i in range(0,N):
    a=int(input())
    if m>=a:
        ans.append(a)
        m=a
    else:
        start=0
        end=len(ans)-1
        while end-start>1:
            test=(end+start)//2
            if a>ans[test]:
                end=test
            else:
                start=test
        if a>ans[start]:
            ans[start]=a
            if start==len(ans)-1:
                m=a
        else:
            ans[end]=a
            if end==len(ans)-1:
                m=a

print(len(ans))
