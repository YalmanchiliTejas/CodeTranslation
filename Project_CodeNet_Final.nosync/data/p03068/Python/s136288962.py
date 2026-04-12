n = input()
s = input()
k = input()

c = s[int(k) - 1]

result = ''
for i in range(int(n)):
    if s[i] != c:
        result += '*'
    else:
        result += s[i]
print(result)
