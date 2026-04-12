n=int(input())
h=list(map(int,input().split()))
max=h[0]
count=1
for i in range(1,n):
    if max<=h[i]:
        count +=1
        max=h[i]
print(count)