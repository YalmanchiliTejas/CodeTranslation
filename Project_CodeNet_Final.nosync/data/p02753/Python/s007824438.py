station = list(input())
message = ""

for i in range(0, len(station)-1):
    if (station[i] != station[i + 1]):
        message = 'Yes'
        break
    else:
        message = 'No'


print(message)
