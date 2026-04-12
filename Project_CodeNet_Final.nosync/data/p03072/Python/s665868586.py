a=int(input())
li = list(map(int,input().split()))
ans = 0
th = 0
for i in range(a):
    if th <= li[i]:
        th = li[i]
        ans += 1

print(ans)