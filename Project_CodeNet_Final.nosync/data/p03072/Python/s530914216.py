n = input()
h_list = [int(i) for i in input().split()]

h_0 = h_list[0]
count = 0
west = [0]

for i in h_list:
    if i >= h_0 and i >= max(west):
        count += 1
    h_0 = i
    west.append(i)

print(count)
