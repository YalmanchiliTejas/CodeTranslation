first = False
while 1:
    n = int(input())
    if n == 0:
        break

    if first:
        print()
    else:
        first = True

    data = []
    for _ in range(n):
        country, win, lose, draw = map(str, input().split())
        point = int(win) * 3 + int(draw)
        data.append([country, point])

    data.sort(key=lambda item: -item[1])

    for country, point in data:
        print(country + "," + str(point))

