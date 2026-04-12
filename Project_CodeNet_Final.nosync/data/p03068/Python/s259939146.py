n = input()
s = input()
k = input()
kaeru = s[int(k)-1]
dst = ""
for i in range(int(n)):
    if s[i]!=kaeru:
        dst = dst + "*"
    else:
        dst = dst + s[i]
print(dst)