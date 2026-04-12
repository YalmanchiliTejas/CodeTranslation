input()
s = input()
k = int(input())

result = [x if x == s[k-1] else "*" for x in s ]
result = "".join(result)
print(result)