n,k=map(int,input().split())

cnt=0
for i in range(1,n+1):
    temp=(n//i)*(i-k)+max((n-(i*(n//i)+k-1)),0) if i-1>=k else 0
    cnt+=min(temp,n)
    #print(temp,i)
print(cnt)