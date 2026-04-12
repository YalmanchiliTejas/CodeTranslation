# B
n = int(input())
s = str(input())
k = int(input())

c = s[k-1]
st = ""
for char in list(s):
    if char == c:
        st = st + char
    else:
        st = st + "*"
print(st)