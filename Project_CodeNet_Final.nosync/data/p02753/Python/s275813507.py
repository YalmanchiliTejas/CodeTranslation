i = input()

c = True
for x in range(1,len(i)):
    if i[0] != i[x]:
        c = False
        print("Yes")
        break

if c:
    print("No")
