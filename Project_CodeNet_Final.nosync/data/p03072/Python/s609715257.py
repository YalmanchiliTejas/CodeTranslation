n = int(input())
mountains = list(map(int, input().split()))
c = 0
ans = 0
for i in mountains:
    if c <= i:
        ans += 1
        c = i
print(ans)