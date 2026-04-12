n = int(input())
h = list(map(int, input().split()))

cnt = 1
maximum = h[0]

for i in range(1, n):
    if(maximum <= h[i]):
        maximum = h[i]
        cnt += 1
        
print(cnt)