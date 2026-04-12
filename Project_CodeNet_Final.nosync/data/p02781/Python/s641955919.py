import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    K = int(input())
    if N <= 1000:
        count = 0
        for i in range(1, N + 1):
            d = 0
            ci = i
            while ci > 0:
                d += (1 if ci % 10 > 0 else 0)
                ci //= 10
            if d == K: count += 1
        print(count)
    else:
        strN = str(N)
        dig = len(strN)
        DPsmall = [[0 for j in range(K + 1)] for i in range(dig)]
        DPsmall[0][0] = 1
        DPsmall[0][1] = int(strN[0]) - 1
        for i in range(1, dig):
            DPsmall[i][0] = 1
            for j in range(1, K + 1):
                DPsmall[i][j] += DPsmall[i-1][j-1] * 9 + DPsmall[i-1][j]
            
        DPlarge = [[0 for j in range(K + 1)] for i in range(dig)] #最初の桁がNの最初と一致
        DPlarge[0][0] = 1
        for i in range(1, dig):
            if strN[i] == "0": DPlarge[i][0] = DPlarge[i-1][0]
            else: DPlarge[i][0] = DPlarge[i-1][0] + 1
            for j in range(1, K + 1):
                if DPlarge[i-1][0] == j - 1: DPlarge[i][j] += (int(strN[i]) - 1 if strN[i] != "0" else 0)
                if DPlarge[i-1][0] == j: DPlarge[i][j] += (1 if strN[i] != "0" else 0)

                DPlarge[i][j] += DPlarge[i-1][j] #i桁目が0
                if j > 1: DPlarge[i][j] += DPlarge[i-1][j-1] * 9 #i桁目は0以上

        ans = DPsmall[dig-1][K] + DPlarge[dig-1][K]
        if DPlarge[dig-1][0] == K: ans += 1
        print(ans)   
        #print(DPsmall)
        #print(DPlarge)

    return 0

if __name__ == "__main__":
    solve()