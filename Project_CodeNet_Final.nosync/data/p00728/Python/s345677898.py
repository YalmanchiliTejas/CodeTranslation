while True:
    N=int(input())
    if(N==0): break
    s = [int(input()) for i in range(N)]
    print(sum(sorted(s)[1:-1]) // (N-2))

