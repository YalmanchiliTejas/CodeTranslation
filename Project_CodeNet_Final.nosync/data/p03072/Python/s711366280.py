n = int(input())
h = list(map(int, input().split()))

ans = 0
hi = 0
for i in  range(n):
    if ( hi <= h[i]):
        ans +=1
        hi = h[i]

print(ans)