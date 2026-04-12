s = str(input())
for i in range(len(s)):
    if s[i] == "A" and s[i+1] == "C":
        print("Yes")
        break
else:
    print("No")