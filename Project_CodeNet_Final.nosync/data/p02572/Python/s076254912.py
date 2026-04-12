num=int(input())
date=list(map(int,input().split(" ")))
sum0=0
sum1=0
for i in range(num):
    sum0+=date[i]
for i in range(num):
    sum0-=date[i]
    sum1+=date[i]*sum0
print(sum1%(10**9+7))