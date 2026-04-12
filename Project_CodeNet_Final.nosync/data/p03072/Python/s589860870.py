num = int(input())
heights = list(map(int,input().split()))
cnt = 1
for i in range(1, num):
    for j in range(0, i):
        if  heights[j] > heights[i]:
             break
    else:
        cnt += 1
print(cnt)
