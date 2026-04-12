n = int(input())
h = list(map(int,input().split()))

minh = 0
ans = 0
for i in h:
    if minh <= i:
        ans += 1
        minh = i

print(ans)