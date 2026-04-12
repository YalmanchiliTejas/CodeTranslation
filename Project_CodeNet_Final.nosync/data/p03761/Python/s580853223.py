n = int(input())
s = [list(input()) for i in range(n)]
ABC = "abcdefghijklmnopqrstuvwxyz"
ans = ""

for moji in ABC:
    count = 50
    for i in s:
        if i.count(moji) < count:
            count = i.count(moji)
    ans += moji * count
print(ans)