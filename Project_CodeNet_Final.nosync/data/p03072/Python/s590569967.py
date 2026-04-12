N = int(input())
li = list(map(int, input().split()))

max = li[0]
ans = 1
for i in range(len(li)-1):
    if max <= li[i+1]:
        max = li[i+1]
        ans += 1
print(ans)
