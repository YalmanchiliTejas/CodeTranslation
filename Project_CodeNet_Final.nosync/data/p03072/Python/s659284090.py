N = int(input())
h = list(map(int, input().split()))
count = 1
left = h[0]
for i in range(1,N):
    if h[i] >= left:
        count += 1
        left = h[i]
print(count)