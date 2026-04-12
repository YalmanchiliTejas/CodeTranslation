arr = [chr(i) for i in range(97, 97+26)]

n = int(input())

s = []
for i in range(n):
    s.append(input())

buf = [0 for i in range(26)]
for i in range(26):
    hoge = 100000000
    for j in range(n):
        fuga = s[j].count(arr[i])
        if fuga < hoge:
            hoge = fuga

    buf[i] = hoge

ans = ""
for i in range(26):
    ans += arr[i]*buf[i]

print(ans)