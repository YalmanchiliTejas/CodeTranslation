def check(N, H):
    max_mount = 0
    count = 0
    mountList = H
    
    for i in mountList:
        if i >= max_mount:
            count += 1
            max_mount = i
    print(count)

N = int(input())
H = [int(i) for i in input().split()]
check(N, H)