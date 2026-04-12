N = input()
H = [int(i) for i in raw_input().split()]

view = 0

max_height = 0
for i in H:
    if i >= max_height:
        view += 1
        max_height = i


print(view)
