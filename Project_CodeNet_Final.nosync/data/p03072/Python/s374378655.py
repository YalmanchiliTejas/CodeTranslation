n = int(input())
h = list(map(int,input().split()))
x = h[0]
ans = 0
for i in h:
    if i >= x:
        ans += 1
        x = i
print(ans)