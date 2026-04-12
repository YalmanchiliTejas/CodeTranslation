import sys
sys.setrecursionlimit(10 ** 5 + 10)
def input(): return sys.stdin.readline().strip()

def resolve():
    
    # https://atcoder.jp/contests/tdpc/tasks/tdpc_number
    # https://atcoder.jp/contests/tdpc/submissions/14489469
    n = input()
    d=int(input())
    # dp[ i ][ smaller ][ d ] := i 桁目までで 0 以外の数の使用数dである数の個数


    dp = [[[0] * (d+2) for _ in range(2)] for _ in range(len(n) + 1)]
    dp[0][0][0] = 1
    
    MOD = 10**9 + 7
    for i in range(len(n)):
        c = ord(n[i]) - ord('0')
        for j in range(d+1):
            # small->small
            dp[i+1][1][j+1]+=dp[i][1][j]*9
            dp[i+1][1][j]+=dp[i][1][j]

            # else->small
            if c>0: # i桁めが0以外
                dp[i + 1][1][j+1]+=dp[i][0][j]*(c-1) #i+1桁目が0以外
                dp[i + 1][1][j]+=dp[i][0][j]#0
            

            # else->else
            if c>0:
                dp[i + 1][0][j+1]+=dp[i][0][j]
            else:
                dp[i+1][0][j]+=dp[i][0][j]
                dp[i + 1][0]
    
    print(dp[len(n)][1][d] + dp[len(n)][0][d])
    
    
    
resolve()