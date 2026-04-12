n = int(input())
li = list(map(int, input().split()))
ans = 0
tmp = li[0]
for num in li:
    if(num >= tmp):
        tmp = num
        ans += 1

print(ans)
