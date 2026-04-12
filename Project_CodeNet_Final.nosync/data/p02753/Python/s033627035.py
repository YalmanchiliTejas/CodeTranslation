s = input()
vis_a = 0
vis_b = 0

for i in s:
  if i == 'A':
    vis_a = 1
  if i == 'B':
    vis_b = 1

if vis_a and vis_b:
    print("Yes")
else:
    print("No")
