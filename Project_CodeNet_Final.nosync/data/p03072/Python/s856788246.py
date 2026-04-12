N = int(input())
H = list(map(int, input().split()))

index = 0
count = 0
can_see_sea = True
for h in H:
    can_see_sea = True
    for _h in H[0:index]:
        if h < _h:
            can_see_sea = False
            continue
    if can_see_sea:
        count = count + 1
    index = index + 1

print(str(count))