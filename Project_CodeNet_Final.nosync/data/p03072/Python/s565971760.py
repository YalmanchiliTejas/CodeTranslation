n=int(input())
h=[int(i) for i in input().split()]

res = 0
best = h[0]
for i in range(n):
    if best <= h[i]:
        res+=1
        best = h[i]
print(res)
