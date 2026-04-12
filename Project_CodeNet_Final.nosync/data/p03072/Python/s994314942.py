def resolve():
    n = int(input())
    h = list(map(int, input().split()))
    count = 1
    height = h[0]
    for i in range(1,len(h)):
        if height <= h[i]:
            count += 1
        height = max(height, h[i])
    print(count)

resolve()