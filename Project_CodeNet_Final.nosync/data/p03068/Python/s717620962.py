n = int(input())
s = input()
k = int(input())
change = s[k - 1]
for i in range(n):
    if s[i] != change:
        print("*", end="")
    else:
        print(s[i], end="")
    if i == n - 1:
        print()