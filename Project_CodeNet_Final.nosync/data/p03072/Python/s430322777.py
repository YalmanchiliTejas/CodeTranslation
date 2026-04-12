number = int(input())

height = []

for i in list(input().split(" ")):
    height.append(int(i))

heightest = 0
view = 0

for i in height:
    if heightest  <= i:
        heightest = i
        view += 1
    else:
        pass

print(view)