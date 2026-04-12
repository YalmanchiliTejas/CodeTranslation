import sys
input = sys.stdin.readline

def main():
    kk = list(input())
    klen = len(kk)-1
    n = 10000
    k = [0]*n
    for i in range(klen-1,-1,-1):
        k[-(klen-i)] = int(kk[i])

    d = int(input())
    mod = 10**9 + 7

    #dp1[i][j] : 上からi桁目まで見てKと同じ時の、数字の総和がj(mod d)の数
    #dp2[i][j] : 上からi桁目まで見てK未満確定時の、数字の総和がj(mod d)の数
    dp1 = [[0]*d for i in range(n+1)]
    dp2 = [[0]*d for i in range(n+1)]

    dp1[0][0] = 1

    for i in range(n):
        for j in range(d):
            for r in range(10):
                if r < k[i]:
                    dp2[i+1][(j+r)%d] = (dp2[i+1][(j+r)%d] + dp1[i][j] + dp2[i][j])%mod
                elif r == k[i]:
                    dp1[i+1][(j+r)%d] = (dp1[i+1][(j+r)%d] + dp1[i][j])%mod
                    dp2[i+1][(j+r)%d] = (dp2[i+1][(j+r)%d] + dp2[i][j])%mod
                else:
                    dp2[i+1][(j+r)%d] = (dp2[i+1][(j+r)%d] + dp2[i][j])%mod



    print((dp1[n][0]+dp2[n][0]-1)%mod)

if __name__ == "__main__":
    main()