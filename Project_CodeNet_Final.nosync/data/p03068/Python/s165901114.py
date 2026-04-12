n = int(input())
s = input()
k = int(input())

c = s[k-1]

def rep(x):
    if x == c:
        return c
    else:
        return "*"


ret = [rep(i) for i in s]

print(''.join(ret))

