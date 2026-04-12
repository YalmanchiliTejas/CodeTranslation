num = int(input())
text = input()
a = int(input())
w = text[a-1]
result = ""

for i in range(num):
    if text[i] == w:
        result += text[i]
    else:
        result += '*'
print(result)
