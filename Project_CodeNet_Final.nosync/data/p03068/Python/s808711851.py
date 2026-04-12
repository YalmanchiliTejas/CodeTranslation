n = int(input())
s = str(input())
k = int(input())
 
char = s[k-1]
result = ""
for x in s:
    if x == char:
        result += char
    else:
        result += "*"
print(result)