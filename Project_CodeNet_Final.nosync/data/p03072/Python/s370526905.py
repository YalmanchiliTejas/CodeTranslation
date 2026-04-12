n = int(input())
h = [ int(i) for i in input().split() ]
ans = 0
for i in range(0,n):
    stat = True
    for j in range(0,i):
        if h[j] > h[i]:
            stat = False
            break
    if stat:
        ans += 1
print(ans)
