station = list(input())
for i in range(2):
    if station[i] != station[i+1]:
        print("Yes")
        break
else:
    print("No")