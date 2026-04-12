bus = input()
buses = []
for i in bus:
    buses.append(i)
ans = set(buses)
if len(ans) == 1:
    print("No")
else:
    print("Yes")