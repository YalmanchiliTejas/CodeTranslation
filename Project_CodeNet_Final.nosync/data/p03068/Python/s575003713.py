jhj = int(input())
moji = list(input())
k = int(input())
o = moji[k - 1]
for c in range(jhj):
    if moji[c] == o:
        pass
    else:
        moji[c] = "*"
print("".join(moji))