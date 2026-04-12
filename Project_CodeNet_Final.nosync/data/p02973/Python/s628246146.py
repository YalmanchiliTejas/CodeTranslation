from bisect import bisect

icase=1
if icase==1:
    n=int(input())
    a=[0]*n
    for i in range(n):
        a[i]=-int(input())
elif icase==2:
    n=5
    a=[-2,-1,-4,-5,-3]
elif icase==3:
    n=4
    a=[0,0,0,0]

def loopa():

    n=len(a)
    dp = [10**10]*(n+1)
    dp[0] = -10**10
    
    for i in range(n):
#        idx = bisect(dp, a[i]-1)
        idx = bisect(dp, a[i])
        dp[idx] = min(a[i], dp[idx])

#        print("i:",i,"a:",a,"dp2:",dp2)            
    return dp

dp=loopa()        

print(bisect(dp, 10**10-1)-1)    

