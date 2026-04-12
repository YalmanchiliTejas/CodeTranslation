n = int(input())
s = input()
k = int(input())

without_change_str = s[k - 1]

result = ""
for char in s:
    result += char if char == without_change_str else "*"
print(result)
