# 2019/07/19
# LCSっぽい？


n=int(input())
s=[sorted(input()) for _ in range(n)]

def lcs(s1,s2):
    dp=[[0]*(len(s2)+1) for _ in range(len(s1)+1)]
    
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i]==s2[j]:
                dp[i+1][j+1]=dp[i][j]+1
            else:
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])

    # 復元

    ans=''
    i,j=len(s1),len(s2)
    while i>=0 and j>=0:
        if dp[i-1][j]==dp[i][j]:i-=1
        elif dp[i][j-1]==dp[i][j]:j-=1
        else:
            ans=s1[i-1]+ans
            i,j=i-1,j-1
    return sorted(ans)

s1=s[0]
for i in range(1,n):
    s2=s[i]
    s1=lcs(s1,s2)

print(''.join(s1))
