N = int(input())
H = map(int,input().split())
max = 0
ans = 0
for h in H:
    if h >= max:
        ans += 1
        max = h
print(ans)
