N = int(input())
H = map(int,input().split())

m = -1
ans = 0
for i in H:
    if m <= i:
        ans += 1
        m = i

print(ans)