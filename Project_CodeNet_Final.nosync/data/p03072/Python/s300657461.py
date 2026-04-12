n = int(input())
h = list(int(i) for i in input().split())
h.insert(0, 0)
count = 0

# print(h)

for i in range(n+2):
    if 1 < i:
        tmp_list = h[0:i]
        my_hotel = h[i-1]
        if max(tmp_list) <= my_hotel:
            count += 1
#        print(i, tmp_list, my_hotel, count)

print(count)