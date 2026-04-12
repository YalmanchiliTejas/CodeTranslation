s = open(0).read()

flag = "No"
for i in range(2):
    if s[i] != s[i + 1]:
        flag = "Yes"
        
print(flag)