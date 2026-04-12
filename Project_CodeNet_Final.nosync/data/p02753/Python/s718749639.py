s = str(input())
station_a = s.count('A')
station_b = s.count('B')
if station_a != 3 and station_b != 3:
    print('Yes')
else:
    print('No')