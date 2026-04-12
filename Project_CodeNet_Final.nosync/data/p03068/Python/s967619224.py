n = int(input())
s = input()
k = int(input())

moji = s[k-1]
answer = ""
for c in s:
    if c == moji:
        answer += c
    else:
        answer += "*"

print(answer)