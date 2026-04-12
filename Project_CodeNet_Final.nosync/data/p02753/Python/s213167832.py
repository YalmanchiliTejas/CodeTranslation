s = input()
before_c = ""
for c in s:
    if(before_c != "" and before_c != c):
        print("Yes")
        break
    before_c = c
else:
    print("No")
    