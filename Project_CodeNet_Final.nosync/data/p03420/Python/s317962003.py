def solve():
    n,k = map(int,input().split())
    res = 0
    for i in range(k+1,n+1):
        res+=(i-k)*(n//i)
        if n%i>=k:
            if k==0:
                res+=n%i
            else:
                res+=n%i-k+1
    print(res)
if __name__=='__main__':
    solve()