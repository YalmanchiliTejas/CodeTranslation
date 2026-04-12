n = int(input())
h = list(map(int,input().split()))
sum = 1
t = 0
for i in range(1,n):
    t = 0
    for j in range(0,i):
        if h[j] <= h[i]:
            t += 1
        else:
            t += 0
    if t == i:
        sum += 1
    else:
        sum += 0

print(sum)
