n = input()
ryokan_height_list = list(map(int, input().split()))

c = 0
for i, target in enumerate(ryokan_height_list):
  impediments = [impediment for impediment in ryokan_height_list[:i] if impediment > target]
  if len(impediments) == 0:
     c += 1

print(c)