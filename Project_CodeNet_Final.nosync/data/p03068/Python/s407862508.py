n = int(input())
s = input()
k = int(input())

ch = s[k - 1]

for c in s:
    if (c == ch):
        print(c, end="")
    else:
        print("*", end="")
