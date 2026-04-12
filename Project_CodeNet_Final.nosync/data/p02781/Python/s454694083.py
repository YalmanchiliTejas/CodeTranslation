from sys import stdin,stdout
def fn(pos,res,k):
    if pos==n:return (k==0)
    ans=0
    if (pos,res,k) in dp:return dp[pos,res,k]
    cur=ord(s[pos])-48
    if res:
        for d in range(cur+1):
            if d==0:ans+=fn(pos+1,d==cur,k)
            elif d!=0 and k>0:ans+=fn(pos+1,d==cur,k-1)
    else:
        for d in range(10):
            if d == 0:ans += fn(pos + 1,0, k)
            elif d != 0 and k > 0:ans += fn(pos + 1,0, k - 1)
    dp[pos,res,k]=ans
    return ans

#a,b=map(int,stdin.readline().split())
s=input()
n=len(s)
k1=int(stdin.readline())
dp={}
ans=0
for d in range(10):
    if d+48<=ord(s[0]):
        ans+=fn(1,(d==ord(s[0])-48),(k1-(d!=0)))
print(ans)