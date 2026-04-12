s = list(input())
for i in range(len(s)):
    if s[i] == "A":
        if s[i + 1] == "C":
            print("Yes")
            exit()
print("No")