n = int(input())
s = input()
k = int(input())

tmp_string = s[k - 1]

for c in s:
    if c == tmp_string:
        print(tmp_string, end="")
    else:
        print("*", end="")
print()