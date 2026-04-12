n = int(input())
h = list(map(int,input().split()))

count = 1
top = h[0]
for i in range(n-1):
    if h[i] <= h[i+1] and top <= h[i+1]:
        count += 1
        top = max(h[i+1],top)
print(count)