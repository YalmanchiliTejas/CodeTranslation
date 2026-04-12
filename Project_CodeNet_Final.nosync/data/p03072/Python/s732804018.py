n = int(input())
h = tuple(map(int,input().split()))
count = 1
mosthigh = h[0]

for i in range(1,n):
    if mosthigh <= h[i]:
        mosthigh = h[i]
        count += 1

print(count)
