if __name__ == '__main__':
    N = int(input())
    H = list(map(int, input().split()))
    
    height = 0
    count = 0
    for i in range(N):
        h = H[i]
        if height <= h:
            count += 1
            height = h
    print(count)