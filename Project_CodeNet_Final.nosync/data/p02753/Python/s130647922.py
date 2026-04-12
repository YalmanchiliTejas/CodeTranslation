s = input()
count = 0
for i in range(3):
    if s[i] == 'A':
        count += 1
if count == 0 or count == 3:
    print("No")
else:
    print("Yes")