n = int(input())
s = input()
k = int(input())
sl = list(s)
rec = sl[k-1]
for i in range(n):
    if sl[i] != rec:
        sl[i] = "*"
print("".join(sl))
