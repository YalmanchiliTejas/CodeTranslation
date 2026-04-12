n = input()
count = 0
for i in range(2):
    if n[i] == n[1 + i]:
        count += 1
    else:
        break
if count == 2:
    print("No")
else:
    print("Yes")
