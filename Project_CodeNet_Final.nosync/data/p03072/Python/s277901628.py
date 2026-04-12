n = int(input())
h = list(map(int,input().split()))
height = h[0]
cnt = 0
for i in h:
    if i >= height:
        cnt = cnt + 1
        height = i
print(cnt)