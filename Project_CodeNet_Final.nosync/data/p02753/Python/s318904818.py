s = input()


cnt = 0
for i in range(3):
    if s[i] == "A":
        cnt += 1

if cnt == 3 or cnt == 0:
    print("No")
else:
    print("Yes")