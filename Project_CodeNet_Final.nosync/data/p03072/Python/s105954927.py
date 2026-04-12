N=int(input())
a=list(map(int,input().split()))
count=0
for i in range(N):
    if(max(a[0:i+1])==a[i]):
        count+=1

print(count)