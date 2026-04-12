num = input()
l = list(map(int, input().split()))

high = 0
count = 0

for bilding in l:
    if bilding > high:
        high = bilding
        count += 1
    elif bilding == high:
        count += 1
    else:
        pass
print(count)