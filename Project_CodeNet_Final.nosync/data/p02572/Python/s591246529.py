N=int(input())
num=list(map(int,input().split()))
goukei=0
for i in range(N):
    goukei += num[i]
    goukei = (goukei%(10**9+7)) 
temp=goukei
sn=0
for i in range(N):
    temp=temp-num[i]
    sn+=num[i]*temp
print(sn%(10**9+7))

