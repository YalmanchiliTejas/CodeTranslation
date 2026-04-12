n = int(input())
l = list(map(int,input().split()))
ans = 0
for i in range(n):
    if i == 0:
        ans += 1
    else:
        if max(l[0:i]) <= l[i]:
            ans += 1
print (ans)
