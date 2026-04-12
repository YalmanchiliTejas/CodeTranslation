n = int(input())
s = input()
k = int(input())

target = s[k-1]

print("".join(c if c == target else '*' for c in list(s)))