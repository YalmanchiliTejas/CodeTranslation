n = int(input())
s = input()
k = int(input())

c = s[k-1]
st = ""
for i in range(n):
    if s[i] != c:
        st += '*'
    else:
        st += s[i]
print(st)