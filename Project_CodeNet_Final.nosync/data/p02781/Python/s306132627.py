def main():
    N=[int(x) for x in list(input())]
    k=int(input())
    digit=len(N)
    if k>digit:
        return 0
    DP=[[[0]*(digit+1) for _ in range(2)] for _ in range(digit+1)] #DP[上からd桁][less][0の個数]
    DP[0][0][0]=1
    for d in range(digit):
        for less in range(2):
            for num in range(digit):
                limit=9 if less else N[d]
                for l in range(limit+1):
                    DP[d+1][less or l<limit][num+(l==0)]+=DP[d][less][num]
    return DP[-1][0][digit-k]+DP[-1][1][digit-k]
    #print(DP)
    
if __name__=='__main__':
    print(main())