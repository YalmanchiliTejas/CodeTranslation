n = int(input())
s = input()
k = int(input())

key = s[k-1]
result =""

for letter in s:
    if letter == key:
        result = result + key
    else:
        result =result +  "*"

print(result)