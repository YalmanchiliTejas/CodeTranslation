import sys
input = sys.stdin.buffer.readline
import numpy as np

def main():
    N,S = map(int,input().split())
    a = list(map(int,input().split()))
    MOD = 998244353
    
    dp = np.zeros(3000+10,dtype=int)
    ans = 0
    
    for num in a:
        dp[0] += 1
        dp[num:] += dp[:-num].copy()
        dp %= MOD
        ans += dp[S]
        
    print(ans%MOD)
    
if __name__ == "__main__":
    main()
