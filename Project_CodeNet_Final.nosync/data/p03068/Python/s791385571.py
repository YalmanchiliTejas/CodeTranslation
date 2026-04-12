n = int(input())
s = input()
k = int(input()) - 1
s_ = s[k]
print("".join([si if si == s_ else "*" for si in s]))