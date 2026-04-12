n = int(input())

H = list(map(int, input().split()))

ans = 0
max_ = -1 
for h in H:
    if h >= max_:
        max_ = h
        ans+=1
print(ans)