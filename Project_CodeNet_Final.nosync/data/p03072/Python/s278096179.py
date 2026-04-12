n=int(input())
h_list = list(map(int,input().split()))


acc = 0
maximum = h_list[0]
for n in h_list:
    tmp = n
    if maximum <= n:
        acc += 1
        maximum = n

print(acc)