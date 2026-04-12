n = int(input())
h = map(int, input().split())

cm = 0
count = 0
for item in h:
    if cm == 0:
        cm = item
        count += 1
    else:
        if cm > item:
            pass
        else:
            cm = item
            count += 1
print(count)