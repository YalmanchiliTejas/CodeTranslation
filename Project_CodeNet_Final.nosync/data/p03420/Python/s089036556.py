if __name__ == '__main__':
    N, K = list(map(int, input().split(' ')))

    if K != 0:
        counter = 0
        for b in range(K+1, N+1):
            counter += (b - K) * ((N+1) // b)
            if N - ((N+1) // b) * b + 1>= K:
                counter += N - ((N+1) // b) * b - K + 1

        print(counter)
    else:
        print(N**2)
