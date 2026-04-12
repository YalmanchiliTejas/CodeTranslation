while True:
    N = int(input())
    if N == 0:
        break
    
    s = [0 for i in range(N)]
    for i in range(N):
        s[i] = int(input())
    print((sum(s) - max(s) - min(s)) // (N - 2))
