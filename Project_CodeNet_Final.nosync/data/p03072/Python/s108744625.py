n = int(input())
h = list(map(int,input().split()))
ans = 1
tmp = h[0]
for i in range(n-1):
        if tmp<=h[i+1]:
                ans += 1
                tmp = h[i+1]
        else:
                continue
print(ans)