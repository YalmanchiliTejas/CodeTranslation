N = int(input())
H = [int(i) for i in input().split()]

count = 0
maximum = 0
for i in H:
    if maximum <= i:
        count += 1
        maximum = i

print(count)