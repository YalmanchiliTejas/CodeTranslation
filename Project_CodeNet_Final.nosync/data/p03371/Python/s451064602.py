
A,B,C,X,Y=map(int,input().split())

anslist=[]

for i in range(0,2*max(X,Y)+1,2):
    ans=C*i
    if X>i//2:
        ans=ans+A*(X-i//2)
    if Y>i//2:
        ans=ans+B*(Y-i//2)
    anslist.append(ans)
print(min(anslist))
    