n=int(input())
h=list(map(int,input().split()))
count=1
w=h[0]
for i in range(1,n):
    if h[i]-w>=0:
        count+=1
        w=h[i]
print(count)