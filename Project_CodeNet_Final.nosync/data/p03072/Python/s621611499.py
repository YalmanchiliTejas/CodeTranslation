N = int(input())
H = list(map(int, input().split()))

height = 0
ans = 0

for h in H:
    if h >= height:
        ans += 1
        height = h
        
print(ans)
