N = int(input())
Hotel_list = list(map(int, input().split()))

ans = 1
highest_hotel = Hotel_list[0]
for i in range(1, N):
    if Hotel_list[i] >= highest_hotel:
        ans += 1
        highest_hotel = Hotel_list[i]
    else:
        pass

print(ans)