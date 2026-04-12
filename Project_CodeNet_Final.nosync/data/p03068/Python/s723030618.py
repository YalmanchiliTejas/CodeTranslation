n = int(input())
s = input()
k = int(input())
a = s[k-1]
s_ = ""
for i in range(n):
    if s[i] != a:
        s_ += "*"
    else:
        s_ += a
print(s_)