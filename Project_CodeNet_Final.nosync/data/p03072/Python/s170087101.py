n = int(input())
h = list(map(int,input().split()))
ans = 0
mx = -1
for i in range(n):
    if(mx<=h[i]):
        mx = h[i]
        ans += 1
print(ans)