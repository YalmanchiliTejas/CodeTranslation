n = int(input())
h = list(map(int, input().split()))
a = h[0]
cnt = 1
for i in range(1,n):
    if h[i] >= a:
        cnt += 1
        a = h[i]
print(cnt)