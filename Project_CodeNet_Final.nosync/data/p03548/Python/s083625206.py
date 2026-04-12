x, y, z = map(int, input().split())
start = x - z
answer = int(start / (y+z))
print(answer)