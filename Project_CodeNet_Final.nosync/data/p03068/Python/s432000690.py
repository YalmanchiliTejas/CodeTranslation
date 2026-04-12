n = int(input())
s = input()
k = int(input())

k -= 1

target = s[k]

ret = list(s)
for i, item in enumerate(s):
    if item != target:
        ret[i] = "*"
print(''.join(ret))



