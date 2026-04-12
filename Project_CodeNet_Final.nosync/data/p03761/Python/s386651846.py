alphabet = "abcdefghijklmnopqrstuvwxyz"
ans = ""

n = int(input())
s = [str(input()) for i in range(n)]

for j in alphabet:
    count = 50
    for k in s:
        if k.count(j) < count:
            count = k.count(j)
    ans += j*count

print(ans)
        