def deque(a): # aの先頭or末尾を得点とする A,Bともに最適解の時得点差x-yを求める
    n=len(a)
    # dp[i][j] : a[i],...,a[j-i]の部分文字列でゲームをスタートしたときの最適解
    dp=[[0 for _ in range(n+1)] for _ in range(n+1)] 
    # 初期条件はdp[i][i]=0
    for length in range(1,n+1):
        for i in range(n-length+1):
            j=i+length
            if (n-(j-i))%2==0: # 先手
                dp[i][j]=max( dp[i+1][j] + a[i] , dp[i][j-1] + a[j-1] )
            else: # 後手
                dp[i][j]=min( dp[i+1][j] - a[i] , dp[i][j-1] - a[j-1] )
    print(dp[0][n])

def main():
    int(input())
    a = list(map(int,input().split()))
    deque(a)
if __name__ == "__main__":
    main()
