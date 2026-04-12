while 1:
    top = 1
    south = 2
    east = 3
    n = input()
    if n == 0:
        break
    Sum = 1
    for i in range(n):
        line = raw_input().strip()
        if line == "North":
            top, south, east = south, 7 - top, east
            Sum += top
        elif line == "East":
            top, south, east = 7- east, south, top
            Sum += top
        elif line == "West":
            top, south, east = east, south, 7 - top
            Sum += top
        elif line == "South":
            top, south, east = 7 - south, top, east
            Sum += top
        elif line == "Right":
            top, south, east = top, east, 7 - south
            Sum += top
        elif line == "Left":
            top, south, east = top, 7 - east, south
            Sum += top
    print Sum