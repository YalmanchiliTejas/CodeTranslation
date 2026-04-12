n,k=map(int,input().split())
cnt=0
if k==0:
    print(n**2)
    exit()

for b in range(1,n+1):
    p=n//b
    r=n-p*b

    if b-1>=k:
        cnt+=p*(b-k)+max(r-k+1,0)
        #print(cnt,num)
print(cnt)
