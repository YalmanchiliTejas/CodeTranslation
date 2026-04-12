sss = list(input())
mozi = sss[0]
hantei = 0
for i in range(1,len(sss)):
    if sss[i] != mozi:
        hantei = 1
        break

if hantei == 1:
    print("Yes")
else:
    print("No")
