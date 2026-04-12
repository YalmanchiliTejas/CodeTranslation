n = int(input())
h = list(map(int, input().split()))

ans = 1
tmp_h = h[0]
for i in range(0,n-1):
    if tmp_h <= h[i+1]:
        ans +=1
        tmp_h = h[i+1]
    else:
        pass
print(ans)