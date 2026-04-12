N = int(input())
S = input()
K = int(input())

l = list(S)

a = l[K-1]

ls = []

for i in l:
    if i == a:
        ls += i
    else:
        ls += '*'

ret = ''.join(ls)

print(ret)