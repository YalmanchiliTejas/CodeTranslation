def main():
    n=int(input())
    A=list(map(int,input().split()))
    if n==3 or n==2:
        return max(A)
    DP=[[None]*3 for _ in range(n)]
    DP[0][0]=A[0]
    DP[1][1]=A[1]
    DP[2][0]=A[0]+A[2]
    DP[2][2]=A[2]
    DP[3][1]=max(A[0],A[1])+A[3]
    #print(DP)
    for i in range(4,n):
        a=A[i]
        if i%2==0:
            DP[i][0]=DP[i-2][0]+a
            DP[i][2]=max(DP[i-2][2]+a,DP[i-3][1]+a,DP[i-4][0]+a)
        if i%2!=0:
            DP[i][1]=max(DP[i-2][1]+a,DP[i-3][0]+a)
    if n%2==1:
        ans=max(DP[-1][2],DP[-2][1],DP[-3][0])
        return ans
    ans=max(DP[-1][1],DP[-2][0])
    return ans
    
if __name__=='__main__':
    print(main())