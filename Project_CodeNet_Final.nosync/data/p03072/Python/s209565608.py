N = int(input())
hotel = list(map(int, input().split()))
ans = 0
max_h = 0
for i in range(N):
    if hotel[i] >= max_h:
        ans += 1
        max_h = hotel[i]
        
print(ans)