num = int(input())
height_raw = input().split()
height = []
for a in range(num):
  height.append(int(height_raw[a])) 

counter = 0
max_height = 0

for b in range(num):
  if height[b]>=max_height:
    max_height = height[b]
    counter += 1

print(counter)
    
  