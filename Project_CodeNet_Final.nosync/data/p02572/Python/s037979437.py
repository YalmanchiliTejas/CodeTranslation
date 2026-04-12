def main():
    N = int(input())
    A = list(map(int,input().split()))
    
    SUM = [sum(A)]
    for i in range(1,N):
        SUM.append((SUM[i-1]-A[i-1])%(10**9+7))
    
    ans = 0
    for i in range(N-1):
        ans += A[i]*SUM[i+1]
        ans = ans%(10**9+7)
    
    print(ans)
    
if __name__ == '__main__':
    main()