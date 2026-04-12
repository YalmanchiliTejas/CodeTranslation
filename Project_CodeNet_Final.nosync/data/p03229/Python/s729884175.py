def main():
    from collections import deque
    N = int(input())
    A = sorted(int(input()) for _ in range(N))

    ans1 = 0
    ans2 = 0
    if N & 1:
        #W型
        a1 = sum(A[N//2+2:])*2+A[N//2+1]+A[N//2]-sum(A[:N//2])*2
        #M型
        a2 = sum(A[N//2+1:])*2-A[N//2]-A[N//2-1]-sum(A[:N//2-1])*2
        print(max(a1,a2))
    else:
        print(sum(A[N//2+1:])*2-sum(A[:N//2-1])*2-A[N//2-1]+A[N//2])










main()