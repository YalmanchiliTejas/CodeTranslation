n = int(input())
s = input()
k = int(input())
a = s[k-1]
print("".join([a if s_ == a else "*" for s_ in s]))