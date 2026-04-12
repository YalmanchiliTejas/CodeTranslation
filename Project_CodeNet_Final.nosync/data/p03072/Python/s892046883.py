n = int(input())
hotels = list(map(int,input().split()))
ans = 1
max_h = hotels[0]
for i in range(1,n):
    if hotels[i]>= max_h:
        ans+=1
        max_h = hotels[i]
print(ans)