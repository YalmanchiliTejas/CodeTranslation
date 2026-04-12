def resolve():
    N = list(input())
    lenN = len(N)
    K = int(input())
    dp = [[[None, None] for _ in range(K+1)] for __ in range(lenN)]

    def rec(i, k, smaller):
        if k==0:
            return 1
        if i>=lenN:
            return 0
        
        if dp[i][k][int(smaller)] is not None:
            return dp[i][k][int(smaller)]
        
        ret = 0
        if smaller:
            ret += rec(i+1, k, True)
            ret += rec(i+1, k-1, True) * 9
        else:
            if N[i] == "0":
                ret += rec(i+1, k, False)
            else:
                ret += rec(i+1, k, True) # 次も0を選ぶ
                ret += rec(i+1, k-1, True) * (int(N[i]) - 1) # 0 < ?? < N[i]
                ret += rec(i+1, k-1, False) # N[i]を選ぶ、真にsmallerとは限らないのでまだFalse
        
        dp[i][k][int(smaller)] = ret
        return ret

    print(rec(0, K, False))
    
    
if __name__ == "__main__":
    resolve()