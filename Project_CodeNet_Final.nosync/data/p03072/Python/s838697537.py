n = int(input())
h = list(map(int,input().split()))
ans = 1
Max = h[0]
for i in range(1,n):
    if h[i] >= Max:
        ans += 1
        Max = h[i]
print(ans)
