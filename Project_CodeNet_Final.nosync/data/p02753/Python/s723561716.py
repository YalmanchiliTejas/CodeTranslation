station = input()

if station[0] == station[1] and station[1] == station[2]:
    print("No")
elif station[0] == station[1] and station[1] != station[2]:
    print("Yes")
else:
    print("Yes")