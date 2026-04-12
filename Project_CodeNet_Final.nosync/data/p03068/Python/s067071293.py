n = int(input())
s = input()
k = int(input())
t = s[k-1]
s = [c if c == t else "*" for c in s]
print("".join(s))