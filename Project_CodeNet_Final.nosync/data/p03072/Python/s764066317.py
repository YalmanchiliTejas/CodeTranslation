n = int(input())
h = list(map(int,input().split()))
cnt = 1
m = h[0]
for i in range(1,n):
    if h[i] >= m:
        cnt += 1
        m = h[i]
print(cnt)