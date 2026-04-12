def MI(): return map(int, input().split())
def II(): return int(input())
def IS(): return input()
def LI(): return list(map(int, input().split()))

n = II()
s = IS()
k = II()
a = []
for i in s:
    if i == s[k-1]:
        a.append(i)
    else:
        a.append('*')
print(''.join(a))
