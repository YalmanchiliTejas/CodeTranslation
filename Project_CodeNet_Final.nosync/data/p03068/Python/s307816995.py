n = int(input())
s = input()
k = int(input())

for c in list(s):
    if c == s[k-1]:
        print(c, end="")
    else:
        print("*", end="")
print("")
