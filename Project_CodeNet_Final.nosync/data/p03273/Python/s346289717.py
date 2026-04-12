nums = [int(num) for num in input().split()]
h = nums[0]
w = nums[1]
a = []
for i in range(h):
    a.append(input())
b = []
for i in range(h):
    hoge = True
    for j in range(w):
        if a[i][j] =="#":
            hoge = False

    if not hoge:
        b.append(a[i])

# print(b)
c = []

for i in range(w):
    hoge = True
    for j in range(len(b)):
        if b[j][i] == "#":
            hoge = False
    if not hoge:
        c.append(i)

ans = []
for i in range(len(b)):
    hoge =""
    for j in range(w):
        if j in c:
            hoge = hoge+b[i][j]
    ans.append(hoge)
        

for i in range(len(ans)):
    print(ans[i])