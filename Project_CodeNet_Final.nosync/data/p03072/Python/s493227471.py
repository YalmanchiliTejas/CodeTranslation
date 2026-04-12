n = int(input())
h = list(map(int, input().split()))
ans = 1
if len(h) == 1:
    print(1)
    exit()
for i in range(1,n):
    li = h[:i]
    if max(li) <= h[i]:
        ans += 1
print(ans)