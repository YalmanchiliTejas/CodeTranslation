s = str(input())
for i in range(1,len(s)):
    if s[i-1] == "A" and s[i] == "C":
        print("Yes")
        exit()
print("No")