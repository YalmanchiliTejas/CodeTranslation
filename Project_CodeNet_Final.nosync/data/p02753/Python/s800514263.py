line = input()
tmp = [0,0,0]
for i in range(3):
    tmp[i] = line[i]
tmp = set(tmp)

if len(tmp) == 1:
    print("No")
if len(tmp) == 2:
    print("Yes")