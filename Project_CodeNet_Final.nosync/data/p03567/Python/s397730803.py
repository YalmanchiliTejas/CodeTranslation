s = input()
out = "No"
for i in range(len(s)):
    if i+1 != len(s):
        if s[i] == "A" and s[i+1] == "C":
            out = "Yes"
print(out)