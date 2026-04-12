n=int(input())
h=list(map(int,input().split()))
res = 0
for i in range(n):
    f = 0
    for j in range(i):
        if h[i]>=h[j]:
            f += 1
    if f == i:
        res += 1
print(res)