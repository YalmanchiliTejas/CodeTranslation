n = int(input())
h = list(map(int, input().split()))
cnt = 1
for i in range(1,n):
    for j in range(0,i):
        if h[i] < h[j]:
            break
        if j == i-1:
            cnt += 1
print(cnt)