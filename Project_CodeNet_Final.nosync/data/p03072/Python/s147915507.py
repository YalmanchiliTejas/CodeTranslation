n = int(input())
h = list(map(int, input().split()))
m = h[0]
num = 1
for i in range(1,n):
    if m <= h[i]:
        m = h[i]
        num += 1
print(num)