n = int(input())
a = 0
li = list(map(int, input().split()))
ans = 0



for i in range(n):
    if li[i] >= a:
        ans += 1
        a = li[i]

print(ans)