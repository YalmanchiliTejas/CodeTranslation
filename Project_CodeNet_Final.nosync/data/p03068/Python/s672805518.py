# n, l = list(map(int, input().split()))
n = int(input())
s = list(input())
k = int(input())
moji = s[k-1]

for i in range(n):
    if s[i] != moji:
        s[i] = "*"
print("".join(s))
