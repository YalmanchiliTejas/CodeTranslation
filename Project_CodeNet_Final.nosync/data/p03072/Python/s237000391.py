n = int(input())
h = [int(i) for i in input().split()]
mx = h[0]
count = 1
for i in range(1,n):
    if mx <= h[i]:
        count += 1
        mx = h[i]
print(count)