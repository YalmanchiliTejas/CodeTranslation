def B():
    N = int(input())
    H = [int(i) for i in input().split()]
    if  not len(H) == N:
        exit()
    max_high = max(H)
    max_index = H.index(max_high)

    count = 0
    count += H.count(max_high)

    pmax = H[0]
    for i in range(max_index):
        if pmax <= H[i]:
            pmax = H[i]
            count += 1
        
    print(count)

if __name__ == '__main__':
    B()
    