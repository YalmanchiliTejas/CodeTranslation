now = 0
ans = 0
n = int(input())
li = list(map(int,input().split()))
for i in li:
    if now <= i:
        now = i
        ans += 1
print(ans)
