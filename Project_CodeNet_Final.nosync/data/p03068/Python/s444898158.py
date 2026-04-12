n = int(input())
s = input()
k = int(input())

for i in range(n):
    print("*" if s[i] != s[k - 1] else s[i], end = "")

print()