def resolve():
    N = int(input())
    H = list(map(int, input().split()))
    count = 0
    for i in range(N):
        if max(H[:i+1]) <= H[i]:
            count += 1
    print(count)
resolve()