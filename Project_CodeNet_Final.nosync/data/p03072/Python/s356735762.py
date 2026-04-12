def check():
    max_mount = 0
    count = 0
    N = int(input())
    mountList = list(map(int, input().split(" ")))
    
    for i in mountList:
        if i >= max_mount:
            count += 1
            max_mount = i
    print(count)
 
check()