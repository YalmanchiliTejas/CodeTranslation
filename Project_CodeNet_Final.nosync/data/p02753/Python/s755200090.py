stations = input()
listStations = list(stations)
if len(set(listStations)) == 2:
    print("Yes")
else:
    print("No")