N = int(input())
H = list(map(int, input().split()))
maximum = 0
count = 0
for n in range(N):
    if maximum <= H[n]:
        maximum = H[n]
        count += 1
print(count)