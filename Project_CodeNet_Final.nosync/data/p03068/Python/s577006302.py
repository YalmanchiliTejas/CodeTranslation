n = int(input())
s = input()
k = s[int(input())-1]
n = ""
for i in s:
    if i != k:
        n += '*'
    else:
        n += k
print(n)
