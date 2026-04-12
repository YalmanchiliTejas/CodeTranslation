n = input()
cnt = 0

for i in n:
    if i == "A":
        cnt += 1

if cnt == 1 or cnt == 2:
    print("Yes")
else:
    print("No")
