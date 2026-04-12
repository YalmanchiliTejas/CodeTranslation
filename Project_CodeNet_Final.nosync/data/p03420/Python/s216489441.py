n,k = map(int,input().split())
ret = 0
for b in range(1, n+1):
    if b<k+1:
        continue
    else:
        m = n//b
        l = n%b
        ret += (b-k)*m
        if k!=0 and l>=k:
            ret += l-k+1
        elif k==0:
            ret += l
print(ret)