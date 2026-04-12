n=int(input())
data=list(map(int,input().split()))
num=0
ans=0
for i in range(len(data)):
    num+=data[i]
for i in range(len(data)):
    num-=data[i]
    temp=(num*data[i])
    ans+=temp
print(ans%(10**9+7))