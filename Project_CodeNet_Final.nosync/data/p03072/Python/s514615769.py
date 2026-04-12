a = int(input())
k = list(map(int,input().split()))
kijun = k[0]
l = 1
for i in range(1,a):
    if k[i] >= kijun:
        l += 1
        kijun = k[i]
print(l)
