len=input()
str=input()
index=input()
safe=str[int(index) - 1]
result = ""
for i in range(int(len)):
    add=safe
    if str[i] != safe:
        add="*"

    result += add

print(result)