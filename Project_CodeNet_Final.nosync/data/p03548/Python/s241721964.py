x, y, z = [int(i) for i in input().split()]

# z + y + z + y + ...+z = (z + y) * k + z <= x
# k <= (x - z)/(z + y)
print(int((x - z)/(z + y)))