REPLACE_CHAR = "*"

n = int(input())
s = list(input())
k = int(input())

keep_char = s[k - 1]
replaced_str = ""

for char in s:
    if char != keep_char:
        replaced_str += REPLACE_CHAR
    else:
        replaced_str += char

print(replaced_str)
