from sys import stdin

s = stdin.readline().rstrip()

result = "No"

if 'A' in s:
    if 'B' in s:
        result = "Yes"

print(result)