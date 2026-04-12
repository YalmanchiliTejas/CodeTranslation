n=int(input())
string=input()
i=int(input())
newString=""
for char in string:
    if char!=string[i-1]:
        newString+="*"
    else:
        newString+=char
print(newString)
