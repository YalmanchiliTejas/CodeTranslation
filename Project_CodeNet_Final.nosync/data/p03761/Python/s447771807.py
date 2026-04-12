import collections

n = int(input())
ans = ''
z = 'abcdefghijklmnopqrstuvwxyz'
c = collections.Counter(z)
for key in c:
    c[key] = 1000
for i in range(n):
    s = input()
    s_1 = collections.Counter(s)
    for j in z:
        if j in s:
            c[j] = min(c[j], s_1[j])
        else:
            c[j] = 0

# print(c)
for key in c:
    if c[key] != 0:
        for i in range(c[key]):
            ans += key
new_str_list = sorted(ans)
new_str = ''.join(new_str_list)
print(new_str)