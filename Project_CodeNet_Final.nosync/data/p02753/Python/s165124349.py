S = input()

count = [0,0]

for s in S:
    if s == "A":
        count[0] +=1
    else:
        count[1] += 1

if count[0] > 0 and count[1] > 0:
    print("Yes")

else:
    print("No")