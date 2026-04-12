n=int(input())
a = list(map(int,input().split()))

total=sum(a)

wa=0
for i in range(n):
    wa+=(a[i]*(total-a[i]))
    total-=a[i]

print(wa%(1000000000+7))