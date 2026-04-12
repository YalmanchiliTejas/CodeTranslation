#%%code
def resolve():
    N=int(input())
    ans=0
    cnt=0
    for i in range(N):
        ans+=800
        cnt+=1
        if cnt==15:
            ans-=200
            cnt=0
    print(ans)
#%%submit!
resolve()
