inp =input()
li = list(input())
num = int(input())
key = li[num-1]
a = []
for q in li:
    if q != key:
        a.append('*')
    else:
        a.append(q)
x = ''.join(a)
print(x)