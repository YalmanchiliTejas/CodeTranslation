N = int(input())
heights = list(map(int, input().split()))
max_height = heights[0]
can_sea = 1;
for i in range(N-1):
  if max_height <= heights[i+1]:
    max_height = heights[i+1]
    can_sea += 1
print("{}" .format(can_sea))