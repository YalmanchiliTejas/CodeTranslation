n = int(input())
s = str(input())
k = int(input())
target_s = s[k-1]
string = ""
for i in s:
    if i == target_s:
        string += target_s
    else:
        string += "*"
print(string)