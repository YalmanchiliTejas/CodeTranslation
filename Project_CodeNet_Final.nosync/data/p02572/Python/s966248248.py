def main():
    N=int(input())
    A=list(map(int,input().split()))

    sumA=sum(A)

    rsumA=A[0]

    res=0
    mod=pow(10,9)+7

    for i in range(len(A)-1):
        res+=A[i]*(sumA-rsumA)
        res=res%mod
        rsumA+=A[i+1]

    print(res)
if __name__=="__main__":
    main()