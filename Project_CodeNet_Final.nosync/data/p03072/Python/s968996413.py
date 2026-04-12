n = int(input())
hotels = list(map(int,input().split()))
cnt = 0
for i in range(n):
    for j in range(n):
        if hotels[j] > hotels[i]:
            break
        if i == j:
            cnt += 1
            break
print(cnt)
                   
            