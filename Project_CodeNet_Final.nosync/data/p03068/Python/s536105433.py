n = int(input())
s = input()
k = int(input())

char = s[k-1]
# print(char)

result=''
for i in range(n):
    if s[i] != char:
        result += '*'
    else:
        result += s[i]

print(result)
