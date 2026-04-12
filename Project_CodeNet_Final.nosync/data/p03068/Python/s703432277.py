n = int(input())
s = input()
k = int(input())
result = []

for x in s:
    if x != s[k-1]:
        result.append("*")
    else:
        result.append(x)

print("".join(result))
