S = input()

zikkou= [0,2]

isto = True

for n in zikkou:
    if S.count("A") == 3 or S.count("B") == 3:
        isto = False


if isto:
    print("Yes")
else:
    print("No")
