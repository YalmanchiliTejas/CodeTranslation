from collections import deque
N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()


def f(A, N):
    l = [0]*N
    a = (N+1)//2

    for i in range(a):
        l[i*2] = A[a-i-1]
    for i in range(N//2):
        l[i*2+1] = A[N-i-1]

    if N%2==1:
        l[-1], l[2] = l[2], l[-1]

    s = 0
    
    for i in range(N-1):
        s += abs(l[i]-l[i+1])

    return s


print(max(f(A, N), f(list(reversed(A)), N)))