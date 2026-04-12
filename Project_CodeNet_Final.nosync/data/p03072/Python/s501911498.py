n=int(input())
h=list(map(int,input().split()))
cnt = 1
max = h[0]
for i in range(n-1):
    if (h[i] <= h[i+1]) and (h[i+1] >= max):
        cnt += 1
        max = h[i+1]
print(cnt)