def main():
    import sys
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int,input().split()))
    
    A = sorted(A)
    K = 0
    while A[-1] >= N:
        M = A[-1]
        p = M//N
        K += p
        for i in range(N-1):
            A[i] += p
        A[-1] -= p*N
        A = sorted(A)
        
    print(K)
    
    
main()