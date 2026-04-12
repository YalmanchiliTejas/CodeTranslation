N = int(input())

H = input().split()

H_int = []
for i in H:
    H_int.append(int(i))

view_capable = 0

max_height = H_int[0]

for j in H_int:
    if j >= max_height:
        view_capable += 1
        max_height = j

print(view_capable)