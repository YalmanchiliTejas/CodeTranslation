# coding: utf-8

no = input()
l = []

for i in range(no):
    a = list(raw_input())
    a.sort()
    l.append("".join(a))

l.sort(key=len)

ans = ""

for mini_char in l[0]:
    is_find = True
    for i, c in enumerate(l[1:]):
        res = l[i].find(mini_char)

        if res == -1:
            is_find = False
            break
        else:
            l[i] = l[i][:res] + l[i][res + 1:]

    if is_find == True:
        ans += mini_char

print ans
