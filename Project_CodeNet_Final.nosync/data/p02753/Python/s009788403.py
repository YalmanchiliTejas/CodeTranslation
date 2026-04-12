s = input()
dic = {"A":False,"B":False}
for c in s:
    dic[c] = True
if dic["A"] and dic["B"]:
    print("Yes")
else:
    print("No")