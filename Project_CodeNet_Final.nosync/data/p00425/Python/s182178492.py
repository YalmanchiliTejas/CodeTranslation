import sys
  
operator = sys.stdin.read().split()
      
top = 1
bottom = 6
south = 2
north = 5
east = 3
west = 4
sum = 1
  
for var in operator[1:]:
    if var == "North":
        north,top,south,bottom = top,south,bottom,north
        sum += top
    elif var == "South":
        south,top,north,bottom = top,north,bottom,south
        sum += top
    elif var == "West":
        west,top,east,bottom = top,east,bottom,west
        sum += top
    elif var == "East":
        east,top,west,bottom = top,west,bottom,east
        sum += top
    elif var == "Right":
        south,east,north,west = east,north,west,south
        sum += top
    elif var == "Left":
        south,west,north,east = west,north,east,south
        sum += top
    else:
        print sum
        top = 1
        bottom = 6
        south = 2
        north = 5
        east = 3
        west = 4
        sum = 1