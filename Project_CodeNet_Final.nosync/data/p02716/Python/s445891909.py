# ABC162F - Select Half

import sys
input = sys.stdin.buffer.readline

def main():
    n=int(input())
    a=list(map(int,input().split()))
    
    if n<4:
        print(max(a))
        sys.exit()

    if n%2:
        #dp[位置][個数]
        dp=[[0,0,0]for i in range(n-2)]
        dp[0]=a[:3]
        for i in range(2,n-1,2):
            dp[i][0]=dp[i-2][0]+a[i]
            dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i+1]
            dp[i][2]=max(dp[i-2][0],dp[i-2][1],dp[i-2][2])+a[i+2]
        print(max(dp[-1]))

    else:
        #dp[位置][個数]
        dp=[[0,0]for i in range(n-1)]
        dp[0]=a[:2]
        for i in range(2,n-1,2):
            dp[i][0]=dp[i-2][0]+a[i]
            dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i+1]
        print(max(dp[-1]))

main()