import bisect
a=[-int(input()) for _ in [0]*int(input())]
dp=[]
for x in a:
    i = bisect.bisect(dp,x)
    if i == len(dp):
        dp.append(x)    
    else:            
        dp[i] = min(dp[i],x)
print(len(dp))