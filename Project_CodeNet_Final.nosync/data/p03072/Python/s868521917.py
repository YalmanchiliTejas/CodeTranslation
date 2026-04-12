n = int(input())
h = list(map(int,input().split()))
s = 0
for i in range(n):
    k = 0
    for j in range(i):
        if h[j] <= h[i]:
            k = k + 1
    if k == i:
        s = s + 1           
print(s)