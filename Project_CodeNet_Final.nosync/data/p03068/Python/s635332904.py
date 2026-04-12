n = int(input())
s = input()
k = int(input())

output = ''
target_char = s[k - 1]

for char in s:
    if char == target_char:
        output += char
    else:
        output += '*'

print(output)
