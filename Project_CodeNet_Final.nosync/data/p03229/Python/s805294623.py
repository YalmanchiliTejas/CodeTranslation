def main():
    import sys
    input = sys.stdin.readline
    N = int(input())
    A = [0] * N
    for n in range(N):
        A[n] = int(input())
    
    A.sort()
    ans1 = sum([-2*a for a in A[:N//2+N%2]]) + sum([2*a for a in A[N//2+N%2:]])
    if N % 2:
        ans1 += A[N//2-1]
        ans1 += A[N//2]
    else:
        ans1 += A[N//2-1]
        ans1 -= A[N//2]

    ans2 = sum([-2*a for a in A[:N//2]]) + sum([2*a for a in A[N//2:]])
    if N % 2:
        ans2 -= A[N//2]
        ans2 -= A[N//2+1]
    else:
        ans2 -= A[N//2]
        ans2 += A[N//2-1]

    print(max(ans1, ans2))

if __name__ == '__main__':
    main()