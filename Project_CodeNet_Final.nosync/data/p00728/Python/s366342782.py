if __name__ == '__main__':
    while True:
        N = int(input())
        if N == 0:
            break

        arr = []
        for _ in range(N):
            arr.append(int(input().strip()))
        
        n = sum(arr)
        n -= max(arr) + min(arr)

        print(n // (N - 2))

