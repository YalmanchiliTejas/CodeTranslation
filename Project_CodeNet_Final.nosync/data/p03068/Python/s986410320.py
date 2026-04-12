a = int(input())
strings = input()
num = int(input())
target = strings[num - 1]
for i in range(a):
    if target != strings[i]:
        strings = strings[:i] + "*" + strings[i + 1:]
print(strings)
