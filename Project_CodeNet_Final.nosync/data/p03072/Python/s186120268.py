N = int(input())
H = list(map(int, input().split()))

max_h = 0
ans = 0

for h in H:
    if max_h <= h:
        ans += 1
        max_h = h
    
print(ans)