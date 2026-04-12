while 1:
    N = int(input())
    if N == 0:break
    print(int(sum(sorted([int(input()) for i in range(N)])[1:-1]) / (N-2)))