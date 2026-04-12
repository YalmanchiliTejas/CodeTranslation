station = [char for char in input()]

station_set = set(station)
if len(station_set) == 2:
    print('Yes')
else:
    print('No')