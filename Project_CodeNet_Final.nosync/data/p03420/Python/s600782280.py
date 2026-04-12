解説AC=True

n,k=map(int,input().split())
cnt=0

if k==0:
    print(n*n)
    exit()

for b in range(k+1,n+1):
    ans=(b-k)*(n//b)+max(0,n%b-k+1)
    cnt+=ans
    
    
print(cnt)