n = int(input())
h = list(map(int, input().split()))
count = 1
if n == 1:
    print(count)
else:
    for i in range(1,n):
        for j in range(0, i):
            if h[j] > h[i]:
                break
        else:
            count += 1
    print(count)