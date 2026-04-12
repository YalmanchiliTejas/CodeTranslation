from os import replace


n = int(input())
s = input()
k = int(input())
replace = s[k - 1]
for i in range(n):
    if s[i] == replace:
        print(s[i],end="")
    else:
        print("*",end="")
print()