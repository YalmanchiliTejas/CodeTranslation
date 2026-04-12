n=int(input())
h=[int(e) for e in input().split()]
ans=1
for i in range(1,n):
    if max(h[:i]) <= h[i]:
        ans += 1
print(ans)