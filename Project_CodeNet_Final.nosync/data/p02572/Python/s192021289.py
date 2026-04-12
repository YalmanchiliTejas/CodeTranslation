def main():
    N = int(input())
    A = list(map(int,input().split()))
    c = [0]*(N)
    c[0] = A[0]%(1000000007)
    for i in range(1,N,1):
        c[i] = c[i-1]+( A[i]%(1000000007) )
        c[i] = c[i]%(1000000007)
    ans = 0
    for i in range(0,N-1,1):
        A[i] = A[i]%(1000000007)
        tmp = (A[i]*(c[N-1]-c[i]))%(1000000007)
        ans += tmp

    return ans%(1000000007)

print(main())
