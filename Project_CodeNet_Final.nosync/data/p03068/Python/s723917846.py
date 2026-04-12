n = int(input())
s = input()
k = int(input())

m = s[k-1]
for ss in s:
    if ss != m:
        print("*", end="")
    else:
        print(ss, end="")
print()